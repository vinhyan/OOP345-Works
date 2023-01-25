#ifndef SDDS_TIMED_TASK_H
#define SDDS_TIMED_TASK_H

#include <iostream>
#include <string>
#include <chrono>

namespace sdds {
   struct Task {
      std::string m_name;
      std::string m_time_unit;
      std::chrono::steady_clock::duration m_duration;
   };

   class TimedTask {
      Task m_tasks[10]{};
      unsigned int m_cnt{};
      std::chrono::steady_clock::time_point m_start_time;
      std::chrono::steady_clock::time_point m_end_time;
   public:
      TimedTask() {};
      void startClock();
      void stopClock();
      void addTask(const char* task);
      unsigned int size()const;
      void display(std::ostream& ostr);

      friend std::ostream& operator<<(std::ostream& ostr, TimedTask& record);
   };

   

}








#endif // !SDDS_TIMED_TASK_H



