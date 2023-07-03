aux_source_directory(. util_files)
add_library(${lib_util} SHARED ${util_files})

target_include_directories(${lib_util} PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/third)

target_link_libraries(${lib_util} PUBLIC zlog)
set_target_properties(${lib_util} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${dist_dir}/lib)
set_target_properties(${lib_util} PROPERTIES VERSION 1.0 SOVERSION 1)
set_target_properties(${lib_util} PROPERTIES INSTALL_RPATH "\${ORIGIN}/../lib")
