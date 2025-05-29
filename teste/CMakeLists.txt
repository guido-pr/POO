cmake_minimum_required(VERSION 3.10)
project(MyTimeProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add include directory
include_directories(include)

# Add source files
add_executable(MyTimeProject
    src/main_bettertime.cpp
    src/MyBetterTime.cpp
    src/MyDate.cpp
    src/MyDateTime.cpp
    src/MyTime.cpp
)