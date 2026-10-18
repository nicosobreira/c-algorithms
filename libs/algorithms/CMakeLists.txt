add_project_library(algorithms)

target_link_libraries(algorithms
  PUBLIC
    data_structures
  PRIVATE
    utils
)
