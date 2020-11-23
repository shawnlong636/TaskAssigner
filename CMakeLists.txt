cmake_minimum_required(VERSION 3.5)

project(final-project-avala022-ybar001-slong024 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

ADD_SUBDIRECTORY(googletest)

if(ANDROID)
  add_library(final-project-avala022-ybar001-slong024 SHARED
    src/main.cpp
    src/mainwindow.cpp
    header/mainwindow.h
    ui/mainwindow.ui
    src/task.cpp
    header/task.h
  )
else()
  add_executable(TaskAssigner
    src/main.cpp
    src/mainwindow.cpp
    header/mainwindow.h
    ui/mainwindow.ui
    src/task.cpp
    header/task.h
  )

  add_executable(unit_tests
      test/test.cpp
  )
endif()

target_link_libraries(TaskAssigner PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(unit_tests ${QT5_LIBRARIES} gtest_main)
