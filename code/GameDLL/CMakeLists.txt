cmake_minimum_required(VERSION 3.10)

# Project name and type
project(dukegame LANGUAGES CXX)

# Set the target as a shared library (DLL)
add_library(dukegame SHARED dllmain.cpp "defs.h")

# Define the export symbol
set_target_properties(dukegame PROPERTIES DEFINE_SYMBOL DLLEXPORT)

# Set the output name for the DLL
set_target_properties(dukegame PROPERTIES OUTPUT_NAME "DN3DGame")