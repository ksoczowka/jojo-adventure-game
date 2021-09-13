cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR "/usr/lib/cmake/SFML")
project(JOJO)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(SRC_LIST
 src/player.cpp
 src/scene.cpp
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/level.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(${PROJECT_NAME} src/main.cpp)
add_library(lib STATIC ${SRC_LIST} inc/properties.hpp)
target_link_libraries(${PROJECT_NAME} lib sfml-graphics sfml-audio)
