cmake_minimum_required(VERSION 3.10)

# Project name and type
project(dukegame LANGUAGES CXX)

# Set the target as a shared library (DLL)
add_library(dukegame SHARED dllmain.cpp "defs.h"  "actor_blimp.cpp" "actor_breakables.cpp" "gibs.cpp" "gibs.h" "actor_core.cpp" "actor_player.cpp" "actor_core.h" "females.cpp" "items.cpp" "toilet.cpp")

# Define the export symbol
set_target_properties(dukegame PROPERTIES DEFINE_SYMBOL DLLEXPORT)

# Set the output name for the DLL
set_target_properties(dukegame PROPERTIES OUTPUT_NAME "DN3DGame")