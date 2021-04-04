cmake_minimum_required(VERSION 3.10)
# Sets the project name
project(Pacstaller VERSION 1.0)
# add the executable
add_executable(Pacstaller pacstaller.cpp)
configure_file(pacstallerconfig.h.in pacstallerconfig.h)
target_include_directories(Pacstaller PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(Pacstaller paclib)
