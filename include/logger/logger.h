#ifndef LOGGER_H_LOGH_LOGGER_H_
#define LOGGER_H_LOGH_LOGGER_H_

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <string_view>

namespace logger {
  static std::ostream& log_stream = std::cout;

  std::ostream& message() {
    auto timestamp = std::chrono::system_clock::now();
    log_stream_ << '[' << std::ctime(&timestamp) << ']' << "MESSAGE" << '|';
    return log_stream;
  }

  std::ostream& warning() {
    auto timestamp = std::chrono::system_clock::now();
    log_stream_ << '[' << std::ctime(&timestamp) << ']' << "WARNING" << '|';
    return log_stream;
  }

  std::ostream& error() {
    auto timestamp = std::chrono::system_clock::now();
    log_stream_ << '[' << std::ctime(&timestamp) << ']' << "ERROR" << '|';
    return log_stream;
  }
}

#endif  // LOGGER_H_LOGH_LOGGER_H
