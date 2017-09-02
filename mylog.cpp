/*
 * My Logging Class
**/
#include <iostream>

#include "mylog.hpp"

namespace MYLOG {

std::unique_ptr<logger_iface> active_logger = nullptr;

static const char normal[] = {0x1b, '[', '0', ';', '3', '9', 'm', 0};
static const char black[]  = {0x1b, '[', '1', ';', '3', '0', 'm', 0};
static const char red[]    = {0x1b, '[', '1', ';', '3', '1', 'm', 0};
static const char green[]  = {0x1b, '[', '0', ';', '3', '2', 'm', 0};
static const char yellow[] = {0x1b, '[', '1', ';', '3', '3', 'm', 0};
static const char blue[]   = {0x1b, '[', '1', ';', '3', '4', 'm', 0};
static const char purple[] = {0x1b, '[', '0', ';', '3', '5', 'm', 0};
static const char cyan[]   = {0x1b, '[', '0', ';', '3', '6', 'm', 0};

logger::logger(log_level level)
: m_level(level) {}

/* General Purpose */
void logger::error(const std::string& msg, const std::string& file, std::size_t line) {
  if (m_level >= log_level::error) {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cerr << "[" << red << "ERROR" << normal << "][" << file << ":" << line << "] " << red << msg << normal << std::endl;
  }
}

void logger::warn(const std::string& msg, const std::string& file, std::size_t line) {
  if (m_level >= log_level::warn) {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[" << yellow << "WARN" << normal << "][" << file << ":" << line << "] " << yellow << msg << normal << std::endl;
  }
}

void logger::info(const std::string& msg, const std::string& file, std::size_t line) {
  if (m_level >= log_level::info) {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[INFO][" << file << ":" << line << "] " << msg << std::endl;
  }
}

void logger::debug(const std::string& msg, const std::string& file, std::size_t line) {
  if (m_level >= log_level::debug) {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[" << blue << "DEBUG" << normal << "][" << file << ":" << line << "] " << blue << msg << normal << std::endl;
  }
}

/* Internal use */
void logger::vinfo(const std::string& msg, const std::string& file, std::size_t line) {
  if (m_level >= log_level::vinfo) {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[" << purple << "VINFO" << normal << "][" << file << ":" << line << "] " << msg << std::endl;
  }
}

void logger::vdebug(const std::string& msg, const std::string& file, std::size_t line) {
  if (m_level >= log_level::vdebug) {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[" << purple << "VDEBUG" << green << "][" << file << ":" << line << "] " << msg << std::endl;
  }
}

/* Everything */
void logger::vall(const std::string& msg, const std::string& file, std::size_t line) {
  if (m_level >= log_level::vall) {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << normal << "[" << purple << "VALL" << purple << "][" << file << ":" << line << "] " << msg << std::endl;
  }
}


/* General Purpose */
void error(const std::string& msg, const std::string& file, std::size_t line) {
  if (active_logger)
    active_logger->error(msg, file, line);
}
void warn(const std::string& msg, const std::string& file, std::size_t line) {
  if (active_logger)
    active_logger->warn(msg, file, line);
}
void info(const std::string& msg, const std::string& file, std::size_t line) {
  if (active_logger)
    active_logger->info(msg, file, line);
}
void debug(const std::string& msg, const std::string& file, std::size_t line) {
  if (active_logger)
    active_logger->debug(msg, file, line);
}

/* Internal use */
void vinfo(const std::string& msg, const std::string& file, std::size_t line) {
  if (active_logger)
    active_logger->vinfo(msg, file, line);
}
void vdebug(const std::string& msg, const std::string& file, std::size_t line) {
  if (active_logger)
    active_logger->vdebug(msg, file, line);
}

/* Everything */
void vall(const std::string& msg, const std::string& file, std::size_t line) {
  if (active_logger)
    active_logger->vall(msg, file, line);
}




} /* MYLOG */
