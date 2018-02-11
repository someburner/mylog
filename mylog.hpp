#pragma once

#include <memory>
#include <mutex>
#include <cstdarg> /* va_list */
#include <stdio.h>
#include <string>

namespace MYLOG {
/* Hack */
constexpr const char* str_end(const char *str) { return *str ? str_end(str + 1) : str; }
constexpr bool str_slant(const char *str) { return *str == '/' ? true : (*str ? str_slant(str + 1) : false); }
constexpr const char* r_slant(const char* str) { return *str == '/' ? (str + 1) : r_slant(str - 1); }
constexpr const char* file_name(const char* str) { return str_slant(str) ? r_slant(str_end(str)) : str; }

/* logger_iface - should be inherited by any class to be used for logging */
class logger_iface {
public:
  /* ctor & dtor */
  logger_iface(void)          = default;
  virtual ~logger_iface(void) = default;
  /* copy ctor & assignment operator */
  logger_iface(const logger_iface&) = default;
  logger_iface& operator=(const logger_iface&) = default;

public:
  /* General Purpose */
  virtual void error(const std::string& msg, const std::string& file, std::size_t line) = 0;
  virtual void warn(const std::string& msg, const std::string& file, std::size_t line)  = 0;
  virtual void okay(const std::string& msg, const std::string& file, std::size_t line)  = 0;
  virtual void info(const std::string& msg, const std::string& file, std::size_t line)  = 0;
  virtual void debug(const std::string& msg, const std::string& file, std::size_t line) = 0;
  /* Internal use */
  virtual void vinfo(const std::string& msg, const std::string& file, std::size_t line) = 0;
  virtual void vdebug(const std::string& msg, const std::string& file, std::size_t line) = 0;
  /* Everything */
  virtual void vall(const std::string& msg, const std::string& file, std::size_t line) = 0;
};

/* default logger class provided by the library */
class logger : public logger_iface {
public:
  /* log level */
  enum class log_level {
    error  = 0,
    warn   = 1,
    info   = 2,
    debug  = 3,
    okay   = 4,
    vinfo  = 5,
    vdebug = 6,
    vall   = 7
  };

public:
  /* ctor & dtor */
  logger(log_level level = log_level::info);
  ~logger(void)          = default;

  /* copy ctor & assignment operator */
  logger(const logger&) = default;
  logger& operator=(const logger&) = default;

public:
   /* General Purpose */
  void error(const std::string& msg, const std::string& file, std::size_t line);
  void warn(const std::string& msg, const std::string& file, std::size_t line);
  void okay(const std::string& msg, const std::string& file, std::size_t line);
  void info(const std::string& msg, const std::string& file, std::size_t line);
  void debug(const std::string& msg, const std::string& file, std::size_t line);
  /* Internal use */
  void vinfo(const std::string& msg, const std::string& file, std::size_t line);
  void vdebug(const std::string& msg, const std::string& file, std::size_t line);
  /* Everything */
  void vall(const std::string& msg, const std::string& file, std::size_t line);

private:
  log_level m_level;
  std::mutex m_mutex;
};

/* variable containing the current logger */
/* by default, not set (no logs) */
extern std::unique_ptr<logger_iface> active_logger;

/* General Purpose */
void error(const std::string& msg, const std::string& file, std::size_t line);
void warn(const std::string& msg, const std::string& file, std::size_t line);
void okay(const std::string& msg, const std::string& file, std::size_t line);
void info(const std::string& msg, const std::string& file, std::size_t line);
void debug(const std::string& msg, const std::string& file, std::size_t line);
/* Internal use */
void vinfo(const std::string& msg, const std::string& file, std::size_t line);
void vdebug(const std::string& msg, const std::string& file, std::size_t line);
/* Everything */
void vall(const std::string& msg, const std::string& file, std::size_t line);

/* Macros */
#ifdef MYLOG_ENABLED
   #ifndef __MYLOG_LOG
   #define __MYLOG_LOG(level, msg) MYLOG::level(msg, MYLOG::file_name(__FILE__), __LINE__);
   #endif
   #ifndef MYLOG_LFLM
   #define MYLOG_LFLM(level, file, line, msg) MYLOG::level(msg, MYLOG::file_name(file), line)
   #endif
#else
   #ifndef __MYLOG_LOG
   #define __MYLOG_LOG(level, msg)
   #endif
   #ifndef MYLOG_LFLM
   #define MYLOG_LFLM(level, file, line, msg)
   #endif
#endif /* MYLOG_ENABLED */

} /* MYLOG */
