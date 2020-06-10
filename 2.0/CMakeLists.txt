cmake_minimum_required(VERSION 3.14)
project(first_lab)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

add_subdirectory(lib/googletest)

include_directories(Lists/headers)
include_directories(Lists/sources)
include_directories(Time_and_Date/headers)
include_directories(Time_and_Date/sources)
include_directories(Tests)
include_directories(lib/googletest/googletest/include)
include_directories(Forms)

add_executable(first_lab main.cpp 
	Tests/Test.cpp Tests/GoogleTest.cpp

	Lists/headers/Interface.h  
	Lists/headers/List.h Lists/sources/List.cpp 
	Lists/sources/Array.cpp Lists/headers/Array.h 
	Lists/sources/Vector.cpp Lists/headers/Vector.h

	Time_and_Date/headers/Date.h Time_and_Date/sources/Date.cpp 
	Time_and_Date/sources/Date_and_Time.cpp Time_and_Date/headers/Date_and_Time.h 
	Time_and_Date/sources/Times.cpp Time_and_Date/headers/Times.h 

	Forms/mainwindow.cpp Forms/mainwindow.h Forms/mainwindow.ui 
	Forms/setdateandtime.cpp Forms/setdateandtime.h Forms/setdateandtime.ui 
	Forms/settime.cpp Forms/settime.h Forms/settime.ui 
	Forms/addelement.cpp Forms/addelement.h Forms/addelement.ui)

target_link_libraries(first_lab gtest)

find_package(Qt5Widgets)

qt5_use_modules(first_lab Widgets)
