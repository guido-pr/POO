cmake_minimum_required(VERSION 3.10)
project(MyDateTimeProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add include directory
include_directories(include)

# Add source files
add_executable(MyDateTimeProject
    src/main.cpp
    src/MyBetterTime.cpp
    src/MyDate.cpp
    src/MyDateTime.cpp
    src/MyTime.cpp
    src/OrderedDateTime.cpp
    src/MyCalendar.cpp
)