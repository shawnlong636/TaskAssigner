# Reference: http://qt-project.org/doc/qt-5.0/qtdoc/cmake-manual.html

cmake_minimum_required(VERSION 3.0)

# Add folder where are supportive functions
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Include Qt basic functions
include(QtCommon)

# Basic information about project

project(final-project-avala022-ybar001-slong024 VERSION 1.0 LANGUAGES CXX)

# Set PROJECT_VERSION_PATCH and PROJECT_VERSION_TWEAK to 0 if not present, needed by add_project_meta
fix_project_version()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set additional project information
# set(COMPANY "Example")
# set(COPYRIGHT "Copyright (c) 2014 Vincent Lee. All rights reserved.")
# set(IDENTIFIER "com.example.Example")

set(SOURCE_FILES
    src/main.cpp
    src/mainwindow.cpp
    header/mainwindow.h
    header/CompletionState.h
    header/Complete.h
    header/Incomplete.h
    header/InProgress
    ui/mainwindow.ui
    src/task.cpp
    src/complete.cpp
    src/incomplete.cpp
    src/inProgress.cpp
    header/task.h
)

# add_project_meta(META_FILES_TO_INCLUDE)

# set(RESOURCE_FILES example.qrc)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# source_group("UI Files" FILES ${UI_FILES})

ADD_SUBDIRECTORY(googletest)

add_executable(TaskAssigner ${OS_BUNDLE} # Expands to WIN32 or MACOS_BUNDLE depending on OS
    ${SOURCE_FILES} ${META_FILES_TO_INCLUDE} ${RESOURCE_FILES}
)

add_executable(unit_tests
    src/complete.cpp
    test/test.cpp
)

target_link_libraries(TaskAssigner Qt5::Widgets)
target_link_libraries(unit_tests ${QT5_LIBRARIES} Qt5::Widgets gtest_main)
