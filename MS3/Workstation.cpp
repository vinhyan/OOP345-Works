// Name: Vinh Nhan
// Seneca Student ID: 171452212
// Seneca email: vnhan1@myseneca.ca
// Date of completion: Apr 8, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

using namespace std;
namespace sdds {
   std::deque<CustomerOrder> g_pending{};
   std::deque<CustomerOrder> g_completed{};
   std::deque<CustomerOrder> g_incomplete{};

   Workstation::Workstation() {}

   Workstation::Workstation(const std::string& record) : Station(record) {}

   void Workstation::fill(std::ostream& os) {
      if (m_orders.size() > 0) {
         //fill the CO at the front of m_orders
         m_orders.front().fillItem(*this, os);
      }
   }

   bool Workstation::attemptToMoveOrder() {
      bool status{};
      //***attempt to move the order at the front:

      //get the first front elm in m_orders
      //CustomerOrder order = move(m_orders.front());
      if (m_orders.size() > 0) {
         CustomerOrder* order = &(m_orders.front());

         //if the order requires no more services or cannot be filled
         if (order->isItemFilled(Station::getItemName()) || !Station::getQuantity()) {
               //move to the next Station
                  //check if the next Station is available

            if (m_pNextStation) { // if yes, move
               m_pNextStation->operator+=(move(*order));
            }
            else { // if no, move order to either g_completed or g_incomplete
               if (order->isOrderFilled()) {
                  // push to g_completed
                  g_completed.push_back(move(*order));
               }
               else {
                  // push to g_incomplete
                  g_incomplete.push_back(move(*order));
               }
            }
            status = true;
            m_orders.pop_front(); //remove the front order 
         }
      }

      // status = TRUE if order has been moved, FALSE otherwise

      return status;
   }

   void Workstation::setNextStation(Workstation* station = nullptr) {
      m_pNextStation = station;
   }

   Workstation* Workstation::getNextStation() const {
      return m_pNextStation;
   }

   void Workstation::display(std::ostream& os) const {
      os << Station::getItemName() << " --> " << (m_pNextStation ? m_pNextStation->getItemName() : "End of line") << endl;

   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
      m_orders.push_back(move(newOrder));
      return *this;
   }

   Workstation::~Workstation() {}







}

