

ot_add_current_dir_to_include_dirs ()

ot_add_source_file ( CosineCovarianceModel.cxx )

ot_install_header_file ( CosineCovarianceModel.hxx )


include_directories (${INTERNAL_INCLUDE_DIRS})

add_library (otcos ${SOURCEFILES})
set_target_properties (otcos PROPERTIES POSITION_INDEPENDENT_CODE ON)
if (BUILD_SHARED_LIBS)
  set_target_properties (otcos PROPERTIES COMPILE_DEFINITIONS "OTCOS_DLL_EXPORTS")
endif ()

if ( NOT DEFINED LIB_VERSION ) 
  set ( LIB_VERSION 0.0.0 )
endif ()
if ( NOT DEFINED LIB_SOVERSION ) 
  set ( LIB_SOVERSION 0 )
endif ()
set_target_properties ( otcos PROPERTIES VERSION ${LIB_VERSION} )
set_target_properties ( otcos PROPERTIES SOVERSION ${LIB_SOVERSION} )
target_link_libraries (otcos ${OPENTURNS_LIBRARY})

# Add targets to the build-tree export set
export (TARGETS otcos FILE ${PROJECT_BINARY_DIR}/otcos-Targets.cmake)

# Install the export set for use with the install-tree
install(EXPORT otcos-Targets
        DESTINATION "${OTCOS_CONFIG_CMAKE_PATH}"
        COMPONENT Development)

install(TARGETS otcos
        EXPORT  otcos-Targets 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${OTCOS_LIBRARY_PATH}
        ARCHIVE DESTINATION ${OTCOS_LIBRARY_PATH}
)

