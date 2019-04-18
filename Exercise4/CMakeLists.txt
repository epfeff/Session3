cmake_minimum_required (VERSION 2.6)
project (PS3-Exercise4)

configure_file (
  "${PROJECT_SOURCE_DIR}/libintegrate.h.in"
  "${PROJECT_BINARY_DIR}/libintegrate.h"
  )

include_directories("${PROJECT_BINARY_DIR}")

add_executable(PS3-Exercise3 main.cpp)


# add_executable(main main.cpp)
# target_link_libraries(main ${CMAKE_SOURCE_DIR}/libbingitup.a)
