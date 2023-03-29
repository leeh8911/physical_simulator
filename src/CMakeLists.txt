add_subdirectory(lib)

if(${BUILD_APP})
    add_subdirectory(app)
    add_dependencies(${PROJECT_APP} ${PROJECT_LIB})
endif(${BUILD_APP})