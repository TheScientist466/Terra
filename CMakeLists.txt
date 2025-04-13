cmake_minimum_required(VERSION 3.26)
project(Terra VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(extlibs)
set(TERRA_BUILD_TESTS true)

file(GLOB src_files "src/*.cpp")
add_executable(${PROJECT_NAME} ${src_files})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system ImGui-SFML::ImGui-SFML)

if(TERRA_BUILD_TESTS)
    enable_testing()
    file(GLOB test_src_files "tests/*.cpp")

    add_executable("TEST_${PROJECT_NAME}" ${test_src_files})
    target_link_libraries("TEST_${PROJECT_NAME}" PUBLIC GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests("TEST_${PROJECT_NAME}")
endif()
