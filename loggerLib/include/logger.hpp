#ifndef __LOGGING_HPP__
#define __LOGGING_HPP__

#include <string>

namespace logging
{
    void TRACE(const std::string &message);
    void DEBUG(const std::string &message);
    void INFO(const std::string &message);
    void WARN(const std::string &message);
    void ERROR(const std::string &message);
    void configure_from_file(std::string config_file);
}

#endif