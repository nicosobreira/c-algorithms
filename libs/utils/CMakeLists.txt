file(GLOB_RECURSE UTILS_SOURCES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/*.c
)

add_library(utils ${UTILS_SOURCES})

target_include_directories(utils
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(utils INTERFACE project_flags)
