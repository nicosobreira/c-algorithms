add_project_library(data_structures)

target_link_libraries(data_structures
  PUBLIC
    compare
    operations
  PRIVATE
    utils
)
