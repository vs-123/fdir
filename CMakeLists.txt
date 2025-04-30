cmake_minimum_required(VERSION 3.26.4)
project(fDir)

find_package(Boost REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} Boost::system Boost::filesystem)
