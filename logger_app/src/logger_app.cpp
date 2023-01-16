#include <thread>
#include <vector>
#include <functional>
#include <memory>
#include <sstream>

#include "logger.hpp"

void work()
{
    std::ostringstream s;
    s << "hi my name is: " << std::this_thread::get_id();
    std::string id = s.str();
    for (size_t i = 0; i < 10000; ++i)
    {
        logging::ERROR(id);
        logging::WARN(id);
        logging::INFO(id);
        logging::DEBUG(id);
        logging::TRACE(id);
    }
}

int main(void)
{
    // configure logging, if you dont it defaults to standard out logging with colors
   // logging::configure({ {"type", "file"}, {"file_name", "test.log"}, {"reopen_interval", "1"} });
    logging::configure_from_file("/home/deon/logger/logger_app/Cfg/logger_config.json");

    // start up some threads
    std::vector<std::shared_ptr<std::thread>> threads(std::thread::hardware_concurrency());
    for (auto &thread : threads)
    {
        thread.reset(new std::thread(work));
    }

    // wait for finish
    for (auto &thread : threads)
    {
        thread->join();
    }

    return 0;
}