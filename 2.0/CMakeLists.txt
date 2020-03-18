cmake_minimum_required(VERSION 3.14)
project(first_lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(Lists/headers)
include_directories(Lists/sources)
include_directories(Time_and_Date/headers)
include_directories(Time_and_Date/sources)
include_directories(Tests)

add_executable(first_lab main.cpp Lists/headers/List.h Lists/sources/List.cpp Time_and_Date/sources/Times.cpp Time_and_Date/headers/Times.h Tests/Test.cpp Time_and_Date/headers/Date.h Time_and_Date/sources/Date.cpp Lists/headers/Interface.h Lists/sources/Array.cpp Lists/headers/Array.h Lists/sources/Vector.cpp Lists/headers/Vector.h Time_and_Date/sources/Date_and_Time.cpp Time_and_Date/headers/Date_and_Time.h)