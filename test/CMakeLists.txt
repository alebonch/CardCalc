cmake_minimum_required(VERSION 3.26)
project(Tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/alebonch/Qt/6.5.2/gcc_64/lib/cmake")


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Test
        REQUIRED)


add_executable(Tests
        ../Calculator.cpp
        ../Calculator.h
        CalculatorTest.cpp
        ../CardGroup.h
        ../CardGroup.cpp
)

enable_testing(true)

add_test(NAME tests COMMAND calculator)

qt_add_executable(tests CalculatorTest.cpp)

target_link_libraries(Tests
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Test
)
