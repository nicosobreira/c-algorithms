cmake_minimum_required(VERSION 3.25)

option(BUILD_TESTING "Build unit tests" OFF)
option(BUILD_EXAMPLES "Build examples" OFF)
option(ENABLE_CLANG_TIDY "Run clang-tidy during the build" OFF)

project(algorithms
  LANGUAGES C
)

add_library(project_flags INTERFACE)

target_compile_features(project_flags INTERFACE c_std_11)

target_compile_definitions(project_flags INTERFACE
  $<$<CONFIG:Debug>:DEBUG>
  $<$<NOT:$<CONFIG:Debug>>:NDEBUG>
)

target_compile_options(project_flags INTERFACE
  $<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wformat=2
    -Wconversion
    -Wsign-conversion
    -Wfloat-conversion
    -Wnull-dereference
    -Wimplicit-fallthrough
    $<$<CONFIG:Debug>:-g>
    $<$<CONFIG:RelWithDebInfo>:-O3;-g;-fno-omit-frame-pointer>
  >

  $<$<C_COMPILER_ID:MSVC>:
    /W4
    /WX
  >
)

if(ENABLE_CLANG_TIDY)
  find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
  if(CLANG_TIDY_EXE)
    set(CMAKE_C_CLANG_TIDY "${CLANG_TIDY_EXE}")
  else()
    message(WARNING "clang-tidy not found, ignoring ENABLE_CLANG_TIDY")
    set(CMAKE_C_CLANG_TIDY "")
  endif()
endif()

# =============================================================================

add_subdirectory(libs/data_structures)
add_subdirectory(libs/algorithms)
add_subdirectory(libs/utils)

if(BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()
