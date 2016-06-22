cmake_minimum_required (VERSION 2.6)

    
# Variables
set(PROJECT_NAME DiceGame)
set(PROJECT_TEST ${PROJECT_NAME}Test)

# Project name
project(${PROJECT_NAME})

# Files
file(GLOB_RECURSE FILES_SRC src/*.cpp)
file(GLOB_RECURSE FILES_TESTS tests/*.cpp)

# Include
include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/tests
    ${PROJECT_SOURCE_DIR}
)

# Set flags to compile C++11 with G++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")


###############################################################################
### GTEST
###############################################################################

# Enable ExternalProject CMake module and set default root directory
include(ExternalProject)
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/libs)

ExternalProject_Add(
    googletest
    URL http://googletest.googlecode.com/files/gtest-1.7.0.zip

    # Disable install step and log output
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON)

# Get properties from googletest
ExternalProject_Get_Property(googletest source_dir)
ExternalProject_Get_Property(googletest binary_dir)

# Set include directory and library parameters
set(GTEST_INCLUDE_DIR ${source_dir}/include)
set(GTEST_LIBRARY_PATH ${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)
set(GTEST_LIBRARY gtest)

# Add library
include_directories(${GTEST_INCLUDE_DIR})
add_library(${GTEST_LIBRARY} UNKNOWN IMPORTED)
set_property(TARGET ${GTEST_LIBRARY} PROPERTY IMPORTED_LOCATION
                ${GTEST_LIBRARY_PATH} )
add_dependencies(${GTEST_LIBRARY} googletest)


# Main Project
add_executable(${PROJECT_NAME} drive.cpp ${FILES_SRC})

# Test suite
add_executable(${PROJECT_TEST} tests.m.cpp ${FILES_SRC} ${FILES_TESTS})
target_link_libraries(${PROJECT_TEST} ${GTEST_LIBRARY} pthread)