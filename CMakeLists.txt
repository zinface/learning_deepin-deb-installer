cmake_minimum_required(VERSION 3.9)

project(mdm_deb_installer)

# Find includes in corrsponding build directories
#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -Wall)

#if(NOT (${CMAKE_BUILD_TYPE} MATCHES "Debug"))
#    set(CMAKE_CXX_FLAGS -j5)
#endif()

# sources file
source_group(HEADERS FILES "*.h")
file(GLOB SOURCES "*.cpp" ${HEADERS})

# Find the library
#find_package(Qt5Widgets)
find_package(PkgConfig REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Concurrent REQUIRED)
find_package(QApt REQUIRED)

pkg_check_modules(DtkCore REQUIRED dtkcore)
pkg_check_modules(DtkWidget REQUIRED dtkwidget)

# Tell CMake to create the executable
add_executable(${PROJECT_NAME} ${SOURCES} resources/resources.qrc)

target_include_directories(${PROJECT_NAME} PUBLIC ${DtkCore_INCLUDE_DIRS} ${DtkWidget_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}
    QApt
    ${DtkCore_LIBRARIES}
    ${DtkWidget_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5Concurrent_LIBRARIES}
)


# install settings
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX /usr)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(FILES mdm_deb_installer.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
