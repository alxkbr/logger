#include "logger.hpp"

void logger::output_generation(log_level_t lvl, string msg)
{
  if(output != nullptr)
  {
    if(log_level <= lvl)
    {
      switch(lvl)
      {
        case LOG_LEVEL_NOISE:   output("[N]"); break;
        case LOG_LEVEL_WARNING: output("[W]"); break;
        case LOG_LEVEL_DEBUG:   output("[D]"); break;
        case LOG_LEVEL_INFO:    output("[I]"); break;
        case LOG_LEVEL_ERROR:   output("[E]"); break;
        case LOG_LEVEL_FATAL:   output("[F]"); break;
      }

      for(auto ext: extensions)
      {
        output("[" + ext() + "]");
      }

      output(" " + msg + "\n");
    }
  }
}

logger::logger(function<void(string msg)> output_cb)
{
  log_level = LOG_LEVEL_NOISE; //all messages by default
  output = output_cb;
}

void logger::set_level(log_level_t lvl)
{
  log_level = lvl;
}

void logger::delete_all_extensions()
{
  extensions.clear();
}

void logger::add_extension(fp ext)
{
  extensions.push_back(ext);
}

void logger::noise(string msg)
{
  output_generation(LOG_LEVEL_NOISE, msg);
}

void logger::warning(string msg)
{
  output_generation(LOG_LEVEL_WARNING, msg);
}

void logger::debug(string msg)
{
  output_generation(LOG_LEVEL_DEBUG, msg);
}

void logger::info(string msg)
{
  output_generation(LOG_LEVEL_INFO, msg);
}

void logger::error(string msg)
{
  output_generation(LOG_LEVEL_ERROR, msg);
}

void logger::fatal(string msg)
{
  output_generation(LOG_LEVEL_FATAL, msg);
}
