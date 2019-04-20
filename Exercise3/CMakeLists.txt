cmake_minimum_required (VERSION 2.6)

project (PS3-Exercise3)

# adds a subdirectory, cmake will search for CMAkeLists.txt in there
add_subdirectory(simpson)

# compile and link main function
add_executable(PS3-Exercise3 main.cpp)
target_link_libraries(PS3-Exercise3 libintegrate)
