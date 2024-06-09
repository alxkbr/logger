#pragma once

#include <list>
#include <string>
#include <functional>

using namespace std;

typedef enum {
  LOG_LEVEL_NOISE, //max., all messages
  LOG_LEVEL_WARNING, //warning, debug, info, error and fatal messages
  LOG_LEVEL_DEBUG, //debug, info, error and fatal messages
  LOG_LEVEL_INFO, //info, error and fatal messages
  LOG_LEVEL_ERROR, //error and fatal messages
  LOG_LEVEL_FATAL, //min., only fatal messages
} log_level_t;

typedef string (*fp)();

class logger
{
  public:
    logger(function<void(string msg)> output_cb);

    void set_level(log_level_t lvl);
    void delete_all_extensions();
    void add_extension(fp);

    void noise(string msg);
    void warning(string msg);
    void debug(string msg);
    void info(string msg);
    void error(string msg);
    void fatal(string msg);

  private:
    function<void(string msg)> output;
    list<fp> extensions;
    log_level_t log_level;

    void output_generation(log_level_t log_level, string msg);
};
