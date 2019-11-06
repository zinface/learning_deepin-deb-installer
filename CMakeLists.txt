cmake_minimum_required(VERSION 3.9)

project(mdm_installer)

# Find includes in corrsponding build directories
#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)
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
#find_package(Qt5Widgets)
find_package(PkgConfig REQUIRED)
find_package(Qt5Widgets REQUIRED)

pkg_check_modules(DtkCore REQUIRED dtkcore)
pkg_check_modules(DtkWidget REQUIRED dtkwidget)

# Tell CMake to create the executable
add_executable(${PROJECT_NAME} ${SOURCES} resources/resources.qrc)

target_include_directories(${PROJECT_NAME} PUBLIC ${DtkCore_INCLUDE_DIRS} ${DtkWidget_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets ${DtkCore_LIBRARIES} ${DtkWidget_LIBRARIES})
