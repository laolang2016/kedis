aux_source_directory(. util_files)
list(APPEND util_files ${PROJECT_SOURCE_DIR}/third/log.c/log.c)
add_library(${lib_util} SHARED ${util_files})

target_include_directories(${lib_util} PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/third)

target_compile_definitions(${lib_util} PUBLIC -DLOG_USE_COLOR)

# target_link_libraries(${lib_util} PUBLIC zlog)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set_target_properties(${lib_util} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${dist_dir}/lib)
    message(STATUS "util path:${dist_dir}/lib")
endif()

set_target_properties(${lib_util} PROPERTIES VERSION 1.0 SOVERSION 1)
set_target_properties(${lib_util} PROPERTIES INSTALL_RPATH "\${ORIGIN}/../lib")
