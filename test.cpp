#include <gtest/gtest.h>
#include <iostream>
#include "logger.hpp"

using namespace std;

ostringstream logout_oss;
ostringstream loglvl_oss;

void to_logout_oss(string msg)
{
  logout_oss << msg;
}

void to_loglvl_oss(string msg)
{
  loglvl_oss << msg;
}

TEST(Logger, Output)
{
  logger log(to_logout_oss);
  log.set_level(LOG_LEVEL_INFO);
  log.info("Info");

  ASSERT_STREQ(logout_oss.str().c_str(), "[I] Info\n");
}

TEST(Logger, Level)
{
  logger log(to_loglvl_oss);
  log.set_level(LOG_LEVEL_INFO);
  log.debug("Debug"); //Shouldn't print because log level is set to 'Info'

  ASSERT_TRUE(loglvl_oss.str().empty());
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
