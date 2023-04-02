cmake_minimum_required(VERSION 3.9)
project(ScreenExercise2)

include_directories(/usr/local/include/LuaCpp)
include_directories(/usr/include/lua5.3/)
add_executable(exercise2 exercise2.cpp)
target_link_libraries(exercise2 luacpp)
target_link_libraries(exercise2 lua5.3)
