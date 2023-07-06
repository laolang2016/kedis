# 指定 cmake 最小版本, 意指 cmake 版本低于指定版本则构建过程终止
cmake_minimum_required(VERSION 3.24)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_BUILD_WITH_INSTALL_RPATH True)

project(kedis_test C)

aux_source_directory(. test_srcs)
add_executable(${PROJECT_NAME} ${test_srcs})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/third
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${lib_klib} ${lib_util})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${dist_dir}/test)

set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "\${ORIGIN}/../lib")

# 执行所有测试
add_test(NAME test_all COMMAND ${PROJECT_NAME})

