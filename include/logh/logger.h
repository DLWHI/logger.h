#ifndef LOGGER_H_LOGH_LOGGER_H_
#define LOGGER_H_LOGH_LOGGER_H_

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <string_view>

namespace logh {
  static std::ostream& log_stream = std::cout;

  enum class log_level {
    notify,
    warning,
    error
  };

  std::ostream& operator<<(std::ostream& os, log_level lvl) {
    switch (lvl) {
      case log_level::notify:
        return os << "NOTIFY";
      case log_level::warning:
        return os << "WARNING";
      case log_level::error:
        return os << "ERROR";
      default:
        throw;
    }
  }


  void log(log_level lvl, const char* msg) {
    auto timestamp = std::chrono::system_clock::now();
    log_stream_ << '[' << std::ctime(&timestamp) << ']' << lvl << '|' << msg << std::endl;
  }

  void log(log_level lvl, const std::string& msg) {
    log(lvl, msg.c_str());
  }

  void log(log_level lvl, const std::string_view& msg) {
    auto timestamp = std::chrono::system_clock::now();
    log_stream_ << '[' << std::ctime(&timestamp) << ']' << lvl << '|' << msg << std::endl;
  }
}

#endif  // LOGGER_H_LOGH_LOGGER_H
