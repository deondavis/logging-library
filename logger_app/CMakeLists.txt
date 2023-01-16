cmake_minimum_required(VERSION 3.9)
project(logger_teastapp DESCRIPTION "logger test application")

include(GNUInstallDirs)

add_executable(logger_testapp src/logger_app.cpp)
set_target_properties(logger_testapp PROPERTIES
    CMAKE_CXX_STANDARD 11)

target_link_libraries(logger_testapp pthread jsoncpp /home/deon/logger/loggerLib/build/libloggerlib.so)

install(TARGETS logger_testapp
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES Cfg/logger_config.json
    DESTINATION ${CMAKE_INSTALL_SYSCONFDIR}/logger_testapp)