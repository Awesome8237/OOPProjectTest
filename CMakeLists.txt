cmake_minimum_required(VERSION 3.27)
project(SFMLTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(SFMLTest main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS audio graphics window system REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(SFMLTest sfml-audio sfml-graphics sfml-window sfml-system)