cmake_minimum_required(VERSION 3.9)
project(loggerlib VERSION 1.0.1 DESCRIPTION "logger shared library")

include(GNUInstallDirs)

add_library(loggerlib SHARED src/logger.cpp)
set_target_properties(loggerlib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    CMAKE_CXX_STANDARD 11
    PUBLIC_HEADER include/logger.hpp)

target_include_directories(loggerlib PUBLIC include)
target_link_libraries(loggerlib pthread jsoncpp)

install(TARGETS loggerlib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})