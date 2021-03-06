# Basic CMake project
cmake_minimum_required(VERSION 2.8.2)

# Output compilation database for clangtidy
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Set default build type to Release
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release.")
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Include the current directory in every build
set(CMAKE_INCLUDE_CURRENT_DIR ON)
 
# Name the project
project(dlx CXX)


# Enable C++14 features on gcc/clang
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(Clang)")
    set(CMAKE_CXX_FLAGS "-Weverything -Wno-c++98-compat -Wno-padded -Werror -std=c++14")
endif()

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GCC)")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -std=c++14")
endif()

add_library(dlx dlx.cpp dlx.h)

# Build executable from sources and headers
add_executable(nqueens dlx test/nqueens.cpp)


