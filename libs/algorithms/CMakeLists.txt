file(GLOB_RECURSE ALGORITHMS_SOURCES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)

add_library(algorithms ${ALGORITHMS_SOURCES})

target_include_directories(algorithms
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(algorithms
  PUBLIC
    data_structures
  PRIVATE
    utils
  INTERFACE
    project_flags
)

