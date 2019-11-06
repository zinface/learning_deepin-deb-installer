cmake_minimum_required(VERSION 2.5)

project(mdm_installer)

# Find includes in corrsponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -Wall)

# source files
# file(GLOB_RECURSE SOURCES "*.cpp")
set(SOURCES
#     ${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/debinstaller.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/filechoosewidget.cpp
)

# header files
# file(GLOB_RECURSE HEADERS "*.h")
set(HEADERS
#     ${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/debinstaller.h
    ${CMAKE_CURRENT_SOURCE_DIR}/filechoosewidget.h
)

# Find the library
find_package(Qt5Widgets)

# Tell CMake to create the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Use the module frome Qt 5
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
