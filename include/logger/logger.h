#ifndef LOGGER_H_LOGH_LOGGER_H_
#define LOGGER_H_LOGH_LOGGER_H_

#include <ctime>
#include <iostream>
#include <string>
#include <string_view>

namespace logger {
  static std::ostream& log_stream = std::cout;

  std::ostream& message() {
    std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    log_stream << '[' << std::ctime(&timestamp) << ']' << "MESSAGE" << '|';
    return log_stream;
  }

  std::ostream& warning() {
    std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    log_stream << '[' << std::ctime(&timestamp) << ']' << "WARNING" << '|';
    return log_stream;
  }

  std::ostream& error() {
    std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    log_stream << '[' << std::ctime(&timestamp) << ']' << "ERROR" << '|';
    return log_stream;
  }
}

#endif  // LOGGER_H_LOGH_LOGGER_H
