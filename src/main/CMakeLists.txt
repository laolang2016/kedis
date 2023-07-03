aux_source_directory(. source_files)
add_executable(${PROJECT_NAME} ${source_files})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE zlog ${lib_klib} ${lib_util})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${dist_dir}/bin)

set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "\${ORIGIN}/../lib")

configure_file(${PROJECT_SOURCE_DIR}/zlog.conf ${CMAKE_BINARY_DIR}/bin/zlog.conf COPYONLY)

