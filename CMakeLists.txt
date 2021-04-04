cmake_minimum_required(VERSION 3.10)
# Sets the project name
project(pacstaller VERSION 1.0)
# add the executable
add_executable(pacstaller pacstaller.cpp)
configure_file(pacstallerconfig.h.in pacstallerconfig.h)
target_include_directories(pacstaller PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(pacstaller paclib)
install(TARGETS pacstaller RUNTIME)
