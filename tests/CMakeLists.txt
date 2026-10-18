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

function(add_unit_test lib file)
  get_filename_component(name ${file} NAME_WE)

  add_executable(${name} ${file})
  target_link_libraries(${name} PRIVATE ${lib} unity project_flags)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/*/test_*.c
)

foreach(test_file ${TEST_FILES})
  file(RELATIVE_PATH rel_path ${CMAKE_CURRENT_SOURCE_DIR} ${test_file})

  string(FIND ${rel_path} "/" first_slash)
  string(SUBSTRING ${rel_path} 0 ${first_slash} lib)

  add_unit_test(${lib} ${test_file})
endforeach()
