#ifndef LOGGER_H_LOGH_LOGGER_H_
#define LOGGER_H_LOGH_LOGGER_H_

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <string_view>

namespace logger {
  static std::ostream& log_stream = std::cout;
  static char time_buf[80] = {0};

  std::ostream& message() {
    std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::strftime(time_buf, sizeof(time_buf), "[%a %b %d %Y %H:%M:%S]", std::localtime(&timestamp));  
    log_stream << time_buf << "MESSAGE" << '|';
    return log_stream;
  }

  std::ostream& warning() {
    std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::strftime(time_buf, sizeof(time_buf), "[%a %b %d %Y %H:%M:%S]", std::localtime(&timestamp)); 
    log_stream << time_buf << "WARNING" << '|';
    return log_stream;
  }

  std::ostream& error() {
   std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::strftime(time_buf, sizeof(time_buf), "[%a %b %d %Y %H:%M:%S]", std::localtime(&timestamp));
    log_stream << time_buf << "ERROR" << '|';
    return log_stream;
  }
}

#endif  // LOGGER_H_LOGH_LOGGER_H
