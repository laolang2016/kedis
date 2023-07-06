aux_source_directory(. klib_files)
add_library(${lib_klib} SHARED ${klib_files})

target_include_directories(${lib_klib} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# target_link_libraries(${lib_klib} PUBLIC zlog)
if(UNIX)
    set_target_properties(${lib_klib} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${dist_dir}/lib)
    message(STATUS "klib path:${dist_dir}/lib")
endif()

set_target_properties(${lib_klib} PROPERTIES VERSION 1.0 SOVERSION 1)

if(UNIX)
    set_target_properties(${lib_klib} PROPERTIES INSTALL_RPATH "\${ORIGIN}/../lib")
endif()

if(WIN32)
    set(lib_klib_name lib${lib_klib}${CMAKE_DEBUG_POSTFIX}${CMAKE_SHARED_LIBRARY_SUFFIX})
    set(lib_klib_fullpath ${CMAKE_CURRENT_BINARY_DIR}/${lib_klib_name})

    if(BUILD_TEST)
        add_custom_command(TARGET ${lib_klib} POST_BUILD
            COMMAND echo klib path:${lib_klib_fullpath}
            COMMAND ${CMAKE_COMMAND} -E copy ${lib_klib_fullpath} $<TARGET_FILE_DIR:kedis>/${lib_klib_name}
            COMMAND ${CMAKE_COMMAND} -E copy ${lib_klib_fullpath}.a $<TARGET_FILE_DIR:kedis>/${lib_klib_name}.a
            COMMAND ${CMAKE_COMMAND} -E copy ${lib_klib_fullpath} $<TARGET_FILE_DIR:kedis_test>/${lib_klib_name}
            COMMAND ${CMAKE_COMMAND} -E copy ${lib_klib_fullpath}.a $<TARGET_FILE_DIR:kedis_test>/${lib_klib_name}.a
        )
    else()
        add_custom_command(TARGET ${lib_klib} POST_BUILD
            COMMAND echo klib path:${lib_klib_fullpath}
            COMMAND ${CMAKE_COMMAND} -E copy ${lib_klib_fullpath} $<TARGET_FILE_DIR:kedis>/${lib_klib_name}
            COMMAND ${CMAKE_COMMAND} -E copy ${lib_klib_fullpath}.a $<TARGET_FILE_DIR:kedis>/${lib_klib_name}.a
        )
    endif()
endif()
