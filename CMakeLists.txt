cmake_minimum_required(VERSION 3.26)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_BUILD_WITH_INSTALL_RPATH True)

project(kedis C)

option(GEN_COVERAGE "构建测试覆盖率" off)
option(BUILD_TEST "构建测试覆盖率" off)

if(CMAKE_BUILD_TYPE)
    string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE)

    if(${BUILD_TYPE} STREQUAL "debug")
        set(project_debug 1)
        set(CMAKE_BUILD_TYPE "Debug")
    elseif(${BUILD_TYPE} STREQUAL "release")
        set(project_debug 0)
        set(CMAKE_BUILD_TYPE "Release")
    else()
        set(project_debug 1)
        set(CMAKE_BUILD_TYPE "Debug")
    endif()
else()
    set(project_debug 1)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

if(project_debug)
    set(CMAKE_DEBUG_POSTFIX d)
endif()

if(project_debug)
    if(GEN_COVERAGE)
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
        SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
    endif()
endif()

set(dist_dir ${CMAKE_BINARY_DIR}/dist)

set(lib_klib klib)
set(lib_util util)

add_subdirectory(src)

if(BUILD_TEST)
    enable_testing()
    add_subdirectory(test)
endif()
