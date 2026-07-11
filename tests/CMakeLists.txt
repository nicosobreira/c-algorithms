include(FetchContent)

FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG        v2.6.1
  SYSTEM
)
FetchContent_MakeAvailable(unity)

if(TARGET unity)
  set_target_properties(unity PROPERTIES C_CLANG_TIDY "")
endif()

function(add_ds_unit_test name file)
  add_executable(${name} "data_structures/${file}")
  target_link_libraries(${name} PRIVATE data_structures unity project_flags)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

function(add_algo_unit_test name file)
  add_executable(${name} "algorithms/${file}")
  target_link_libraries(${name} PRIVATE algorithms unity project_flags)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

add_ds_unit_test(test_list test_list.c)

add_algo_unit_test(test_insertion_sort sort/test_insertion_sort.c)

add_algo_unit_test(test_binary_search search/test_binary_search.c)
