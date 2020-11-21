cmake_minimum_required(VERSION 3.5)

project(TaskAssigner LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

ADD_SUBDIRECTORY(googletest)


add_executable(TaskAssigner
src/main.cpp
src/mainwindow.cpp
header/mainwindow.h
ui/mainwindow.ui
)

add_executable(unit_tests
  test/test.cpp
)

target_link_libraries(TaskAssigner PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(unit_tests ${QT5_LIBRARIES} gtest_main)