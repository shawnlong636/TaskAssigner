cmake_minimum_required(VERSION 3.5)

project(final-project-avala022-ybar001-slong024 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


add_executable(TaskAssigner
src/main.cpp
src/mainwindow.cpp
header/mainwindow.h
ui/mainwindow.ui
)

target_link_libraries(TaskAssigner PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
