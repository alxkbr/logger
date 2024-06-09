#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "logger.hpp"

using namespace std;

string ext_time()
{
  auto t = time(nullptr);
  auto tm = *localtime(&t);

  ostringstream oss;
  oss << put_time(&tm, "%d-%m-%Y %H:%M:%S");
  auto str = oss.str();

  return str;
}

void to_stdout(string msg)
{
  cout << msg;
}

int main()
{
  logger log(to_stdout);
  log.set_level(LOG_LEVEL_DEBUG);
  log.info("Hello Venstar!!!\n");

  log.add_extension(ext_time);
  {
    log_level_t log_levels[] = {
      LOG_LEVEL_NOISE,
      LOG_LEVEL_WARNING,
      LOG_LEVEL_DEBUG,
      LOG_LEVEL_INFO,
      LOG_LEVEL_ERROR,
      LOG_LEVEL_FATAL,
    };

    for(auto lvl: log_levels)
    {
      log.set_level(lvl);

      cout << "Log level:" << lvl << endl;

      log.noise("Noise");
      log.warning("Warning");
      log.debug("Debug");
      log.info("Info");
      log.error("Error");
      log.fatal("Fatal");

      cout << endl;
    }
  }
  log.delete_all_extensions();

  log.set_level(LOG_LEVEL_INFO);
  log.info("Venstar have a nice day!!!");

  return 0;
}
