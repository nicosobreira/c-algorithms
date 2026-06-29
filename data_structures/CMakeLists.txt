file(GLOB_RECURSE DATA_STRUCTURES_SOURCES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)

add_library(data_structures ${DATA_STRUCTURES_SOURCES})

target_include_directories(data_structures
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(data_structures INTERFACE project_flags)
