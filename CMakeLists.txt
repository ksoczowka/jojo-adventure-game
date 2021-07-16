cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR "/usr/lib/cmake/SFML")
project(JOJO)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(SRC_LIST
 src/player.cpp
    )

add_executable(${PROJECT_NAME} src/main.cpp)
add_library(lib STATIC ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} lib sfml-graphics sfml-audio)
