cmake_minimum_required(VERSION 3.10)

project(BelgianChocolateDuke3D)

set(SDL2_DIR "${CMAKE_SOURCE_DIR}/SDL2-2.30.5/cmake/")

set(SDL2Mixer_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SDL2_mixer-2.8.0/include/")
set(SDL2Mixer_LIBRARY "${CMAKE_SOURCE_DIR}/SDL2_mixer-2.8.0/lib/x64/SDL2_mixer.lib")


# Output everything into bin/ and lib/
set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# Ignore the Configuration sub-directory on Visual Studio.
foreach (OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/lib)
endforeach()

# CMake extensions
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

if (WIN32)

	add_definitions(-DWIN32_LEAN_AND_MEAN)
	add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE)
	
	# Statically link against the multithreaded runtime.
	foreach (flag_var CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE CMAKE_C_FLAGS_MINSIZEREL CMAKE_FLAGS_RELWITHDEBINFO)
		if (${flag_var} MATCHES "/MD")
			string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
		endif()
	endforeach()
	
	# Compile files in parallel
	add_compile_options("/MP")
	
endif()

if (UNIX)
		
	add_definitions(-DUNIX)
	add_compile_options("-Wall")

	# Duke 3D source code is not at all thought out for strict aliasing.
	# Really not! It's full of dangerous pointer casting.
	# Without this option, game will crash at random places when compiled with -O2 or-O3.
	add_compile_options("-fno-strict-aliasing") 

	# Duke 3D source code has a few redefinitions of global types in its headers.
	add_compile_options("-fcommon")

endif ()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(project_suffix ".64")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
	set(project_suffix ".32")
endif()

find_package(SDL2 CONFIG REQUIRED)

if (VCPKG_TARGET_TRIPLET)
	# On Windows and MacOS we can use vcpkg to build all the dependencies.
	find_package(SDL2_mixer CONFIG REQUIRED)
	set(SDL2_ALL_LIBRARIES 
		$<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static> 
		$<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>)
else()
	# On Linux we have to rely on the package system (e.g. apt-get).
	# Otherwise we are likely to be missing some SDL-mixer components (e.g. proper MIDI sound support).
	find_path(SDL2_INCLUDE_DIR SDL2/SDL.h)
	find_package(SDL2Mixer REQUIRED)
	set(SDL2_ALL_LIBRARIES ${SDL2_LIBRARIES} ${SDL2Mixer_LIBRARIES})
endif()

add_subdirectory(Engine)
add_subdirectory(Game)
add_subdirectory(GameDLL)
set_property (DIRECTORY PROPERTY VS_STARTUP_PROJECT Game)
