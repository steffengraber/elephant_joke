cmake_minimum_required(VERSION 3.15)

project(elephant_joke LANGUAGES CXX)

find_package(pybind11 REQUIRED)
find_package(Python REQUIRED COMPONENTS Interpreter Development)

pybind11_add_module(elephant_joke_module src/elephant_joke.cpp)

target_include_directories(elephant_joke_module PRIVATE ${Python_INCLUDE_DIRS})

install(TARGETS elephant_joke_module
  LIBRARY DESTINATION elephant_joke
)
