include(FetchContent)

FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG        v2.6.1
  SYSTEM # This ignores project_flags for unity
)
FetchContent_MakeAvailable(unity)

if(TARGET unity)
  set_target_properties(unity PROPERTIES C_CLANG_TIDY "")
endif()

function(add_unit_test lib name file)
  add_executable(${name} "${lib}/${file}")
  target_link_libraries(${name} PRIVATE ${lib} unity project_flags)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

add_unit_test(compare test_compare test_compare.c)

add_unit_test(data_structures test_list test_list.c)

add_unit_test(algorithms test_insertion_sort sort/test_insertion_sort.c)

add_unit_test(algorithms test_binary_search search/test_binary_search.c)

add_unit_test(algorithms test_has_two_sum search/test_has_two_sum.c)
