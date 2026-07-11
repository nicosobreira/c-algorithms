file(GLOB_RECURSE COMPARE_SOURCES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)

add_library(compare ${COMPARE_SOURCES})

target_include_directories(compare
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(compare
  PRIVATE
    utils
  INTERFACE
    project_flags
)
