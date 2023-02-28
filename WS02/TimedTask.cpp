/*
Full name: Vinh Nhan
Student ID: 171452212
OOP345 - Workshop 2
Date: Jan 27, 2023
*/
#include <chrono>
#include <iomanip>
#include "TimedTask.h"


using namespace std;
namespace sdds {
   void TimedTask::startClock() {
      m_start_time = chrono::steady_clock::now();
   }
   void TimedTask::stopClock() {
      m_end_time = chrono::steady_clock::now();
   }
   void TimedTask::addTask(const char* task) {
      if ((task && task[0] != '\0') && m_cnt < 10) {
         m_tasks[m_cnt].m_name = task;
         m_tasks[m_cnt].m_time_unit = "nanoseconds";
         m_tasks[m_cnt].m_duration = chrono::duration_cast<std::chrono::nanoseconds>(m_end_time - m_start_time);
         m_cnt++;
      }
   }
   unsigned int TimedTask::size() const{
      return m_cnt;
   }

   void TimedTask::display(std::ostream& ostr) const {
      for (unsigned int i = 0; i < m_cnt; i++) {
         ostr << left  << setw(21) << m_tasks[i].m_name << " " 
              << right << setw(13) << m_tasks[i].m_duration.count() << " " 
              << m_tasks[i].m_time_unit << endl;
      }
   }
   std::ostream& operator<<(std::ostream& ostr, const TimedTask& record) {
      ostr << "--------------------------" << endl
           << "Execution Times:" << endl
           << "--------------------------" << endl;
      record.display(ostr);
      ostr << "--------------------------" << endl;
      return ostr;
   }
}




