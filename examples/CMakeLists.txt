file(GLOB_RECURSE EXAMPLES_SOURCES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)

add_executable(example ${EXAMPLES_SOURCES})

target_link_libraries(example PRIVATE algorithms INTERFACE project_flags)
