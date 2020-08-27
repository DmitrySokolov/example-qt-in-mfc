cmake_minimum_required(VERSION 3.16)

project(Dll LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


add_library(${PROJECT_NAME} SHARED
  main.cpp
  mydialog.cpp
  mydialog.h
  mydialog_api.h
  mydialog.ui
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    PUBLIC_HEADER mydialog_api.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


get_filename_component(QT_BIN_DIR "${QT_QMAKE_EXECUTABLE}" DIRECTORY CACHE)
get_filename_component(MY_INSTALL_DIR "${CMAKE_SOURCE_DIR}/../Install" ABSOLUTE CACHE)
set(CMAKE_INSTALL_PREFIX ${MY_INSTALL_DIR} CACHE PATH "" FORCE)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
install(CODE "execute_process(COMMAND \"${QT_BIN_DIR}/windeployqt.exe\" --dir \"${MY_INSTALL_DIR}/bin\" \"$<TARGET_FILE:${PROJECT_NAME}>\")")
