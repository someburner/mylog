/* Basic example */
#include <iostream>
#include <mylog/mylog.hpp>

#include "debug.h"

int main()
{
   try {
      MYLOG::active_logger = std::unique_ptr<MYLOG::logger>(new MYLOG::logger(MYLOG::logger::log_level::okay));
   } catch (std::exception& e) {
      std::cout << "Oh dear :( [" << e.what() << "]" << std::endl;
      exit(1);
   }

   std::cout << "Im normal" << std::endl;
   log("Im debug");
   logokay("Im okay");
   loginfo("Im info");
   logwarn("Im warn");
   logerror("Im error");

}
