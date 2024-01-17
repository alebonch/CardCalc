cmake_minimum_required(VERSION 3.26)
project(CardCalc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/alebonch/Qt/6.5.2/gcc_64/lib/cmake")


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(CardCalc main.cpp
        CardGroup.cpp
        CardGroup.h
        Calculator.cpp
        Calculator.h
        Calculator.cpp
        Calculator.h
        Calculator.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)
target_link_libraries(CardCalc
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

