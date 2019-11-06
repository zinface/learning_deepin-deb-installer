cmake_minimum_required(VERSION 2.5)

project(mdm_installer)

# Find includes in corrsponding build directories
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -Wall)

if(NOT (${CMAKE_BUILD_TYPE} MATCHES "Debug"))
    set(CMAKE_CXX_FLAGS -03)
endif()

# sources file
file(GLOB SOURCES "*.h" "*.cpp")

# Find the library
find_package(Qt5Widgets)

# Tell CMake to create the executable
add_executable(${PROJECT_NAME} ${SOURCES} resources/resources.qrc)

# Use the module frome Qt 5
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
