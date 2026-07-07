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

function(add_unit_test name lib)
  add_executable(${name} ${ARGN})
  target_link_libraries(${name} PRIVATE ${lib} unity project_flags)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

add_unit_test(test_list data_structures data_structures/test_list.c)

# add_unit_test(test_sorting algorithms algorithms/test_sorting.c)
