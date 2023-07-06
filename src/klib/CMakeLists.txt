aux_source_directory(. klib_files)
add_library(${lib_klib} SHARED ${klib_files})

target_include_directories(${lib_klib} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# target_link_libraries(${lib_klib} PUBLIC zlog)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set_target_properties(${lib_klib} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${dist_dir}/lib)
    message(STATUS "klib path:${dist_dir}/lib")
endif()

set_target_properties(${lib_klib} PROPERTIES VERSION 1.0 SOVERSION 1)
set_target_properties(${lib_klib} PROPERTIES INSTALL_RPATH "\${ORIGIN}/../lib")
