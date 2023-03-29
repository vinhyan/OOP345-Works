// Name: Vinh Nhan
// Seneca Student ID: 171452212
// Seneca email: vnhan1@myseneca.ca
// Date of completion: Apr 8, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {
   //accessible PLEASE USE extern
   extern std::deque<CustomerOrder> g_pending;
   extern std::deque<CustomerOrder> g_completed;
   extern std::deque<CustomerOrder> g_incomplete;

   class Workstation : public Station {
      std::deque<CustomerOrder> m_orders{};
      Workstation* m_pNextStation{};
   public:
      //copy & move need to be deleted
      Workstation(const Workstation& src) = delete;
      Workstation& operator=(const Workstation& src) = delete;
      Workstation(Workstation&& src) = delete;
      Workstation& operator=(Workstation&& src) = delete;

      Workstation();
      Workstation(const std::string& record);
      void fill(std::ostream& os);
      bool attemptToMoveOrder();
      void setNextStation(Workstation* station);
      Workstation* getNextStation() const;
      void display(std::ostream& os) const;
      Workstation& operator+=(CustomerOrder&& newOrder);
      ~Workstation();
   };






}





#endif // !SDDS_WORKSTATION_H

