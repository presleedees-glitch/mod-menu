cmake_minimum_required(VERSION 3.22)

project(my-cool-mod VERSION 0.1.0)

# QPM packages
include(qpm_defines.cmake)

# Shared library
add_library(${CMAKE_PROJECT_NAME} SHARED
    src/main.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    include
    ${EXTERN_DIR}/includes
)

# C++20
target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_20)

# Strip in release
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
    -Wall -Wextra -Werror
    -O2 -DNDEBUG
)

# QPM link
qpm_setup_module()
