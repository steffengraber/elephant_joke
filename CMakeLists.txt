cmake_minimum_required(VERSION 3.18)

project(elephant_joke LANGUAGES CXX)

# Use pybind11's built-in Python detection
set(PYBIND11_FINDPYTHON ON CACHE BOOL "Use pybind11's FindPython")
find_package(pybind11 REQUIRED)

pybind11_add_module(elephant_joke_module src/elephant_joke.cpp)

target_include_directories(elephant_joke_module PRIVATE ${Python_INCLUDE_DIRS})

install(TARGETS elephant_joke_module
  LIBRARY DESTINATION elephant_joke
)
