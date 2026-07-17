function(add_example name)
  add_executable(${name} ${ARGN})
  target_link_libraries(${name} PRIVATE algorithms project_flags)
endfunction()

add_example(compare_example src/compare.c)
