cmake_minimum_required(VERSION 3.15)

project(elephant_joke LANGUAGES CXX)

find_package(pybind11 REQUIRED)
find_package(Python REQUIRED COMPONENTS Interpreter Development)

pybind11_add_module(_elephant_joke src/elephant_joke.cpp)

target_include_directories(_elephant_joke PRIVATE ${Python_INCLUDE_DIRS})

install(TARGETS _elephant_joke
  LIBRARY DESTINATION elephant_joke
)
