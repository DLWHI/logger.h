#ifndef LOGGER_H_LOGGER_LOGGER_H_
#define LOGGER_H_LOGGER_LOGGER_H_

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <string_view>

class logger {
 private:
  static constexpr char time_buf_size_ = 25;

  static std::ostream*& log_stream() noexcept {
    static std::ostream* lgs = &std::cout;
    return lgs;
  }
  
  static char* time_buf() noexcept {
    static char buf[25] = {0};
    return buf;
  }
 
 public:
  static std::ostream& message() {
    std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::strftime(time_buf(), time_buf_size_, "[%a %b %d %Y %H:%M:%S]", std::localtime(&timestamp));  
    *log_stream() << time_buf() << "MESSAGE" << '|';
    return *log_stream();
  }

  static std::ostream& warning() {
    std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::strftime(time_buf(), time_buf_size_, "[%a %b %d %Y %H:%M:%S]", std::localtime(&timestamp)); 
    *log_stream() << time_buf() << "WARNING" << '|';
    return *log_stream();
  }

  static std::ostream& error() {
   std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::strftime(time_buf(), time_buf_size_, "[%a %b %d %Y %H:%M:%S]", std::localtime(&timestamp));
    *log_stream() << time_buf() << "ERROR" << '|';
    return *log_stream();
  }

  static void set_log_stream(std::ostream& stream) { log_stream() = &stream; }
};

#endif  // LOGGER_H_LOGGER_LOGGER_H_

