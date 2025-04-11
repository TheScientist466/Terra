cmake_minimum_required(VERSION 3.26)
project(Terra VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(extlibs)

file(GLOB src_files "src/*.cpp")
add_executable(${PROJECT_NAME} ${src_files})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system ImGui-SFML::ImGui-SFML)
