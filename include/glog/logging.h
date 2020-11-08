#pragma once

#include <iostream>
#include <string>
#include <sstream>

class glog_log
{
public:
  glog_log() : cond(false) {}
  glog_log(const std::string& level, bool condition) : lvl(level), cond(condition)
  {
    if (cond) {
      std::cout << level << ": ";
    }
  }

  ~glog_log()
  {
    if (cond)
    {
      std::cout << std::endl;
      if (lvl == "FATAL") {
        exit(1);
      }
    }
  }

  template<typename T>
  glog_log& operator<<(const T &t)
  {
    if (cond) {
      std::cout << t;
    }
    return *this;
  }

private:
  std::string lvl;
  bool cond;
};


#define LOG(lvl)          glog_log(#lvl, true)
#define LOG_IF(lvl, cond) glog_log(#lvl, (cond))

#define CHECK(cond)       LOG_IF("FATAL", !(cond))
#define CHECK_EQ(x, y)    LOG_IF("FATAL", !(x == y))
#define CHECK_NE(x, y)    LOG_IF("FATAL", !(x != y))
#define CHECK_LT(x, y)    LOG_IF("FATAL", !(x < y))
#define CHECK_LE(x, y)    LOG_IF("FATAL", !(x <= y))
#define CHECK_GT(x, y)    LOG_IF("FATAL", !(x > y))
#define CHECK_GE(x, y)    LOG_IF("FATAL", !(x >= y))
#define CHECK_NOTNULL(x)  LOG_IF("FATAL", !(x != 0))

#ifdef NDEBUG
  #define DLOG(lvl)         glog_log()
  #define DLOG_IF(lvl)      glog_log()
  #define DCHECK(cond)      glog_log()
  #define DCHECK_EQ(x, y)   glog_log()
  #define DCHECK_NE(x, y)   glog_log()
  #define DCHECK_LT(x, y)   glog_log()
  #define DCHECK_LE(x, y)   glog_log()
  #define DCHECK_GT(x, y)   glog_log()
  #define DCHECK_GE(x, y)   glog_log()
  #define DCHECK_NOTNULL(x) glog_log()
#else
  #define DLOG            LOG
  #define DLOG_IF         LOG_IF
  #define DCHECK          CHECK
  #define DCHECK_EQ       CHECK_EQ
  #define DCHECK_NE       CHECK_NE
  #define DCHECK_LT       CHECK_LT
  #define DCHECK_LE       CHECK_LE
  #define DCHECK_GT       CHECK_GT
  #define DCHECK_GE       CHECK_GE
  #define DCHECK_NOTNULL  CHECK_NOTNULL
#endif


namespace google
{
  static inline void InitGoogleLogging(const char* arg) {}
}
