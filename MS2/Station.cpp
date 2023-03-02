// Name: Vinh Nhan
// Seneca Student ID: 171452212
// Seneca email: vnhan1@myseneca.ca
// Date of completion: Mar 1, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"


namespace sdds {
   size_t Station::m_widthField = 0;
   int Station::m_id_generator = 0;

   Station::Station(const std::string& record) {
      Utilities util;
      size_t next_pos{};
      bool more = true;
      m_itemName = util.extractToken(record, next_pos, more);
      m_serialNum = stoi(util.extractToken(record, next_pos, more));
      m_availQty = stoi(util.extractToken(record, next_pos, more));
      if (m_widthField < util.getFieldWidth()) m_widthField = util.getFieldWidth();
      m_desc = util.extractToken(record, next_pos, more);
      m_id = ++m_id_generator;

   }

   const std::string& Station::getItemName() const {
      return m_itemName;
   }

   size_t Station::getNextSerialNumber() {
      return m_serialNum++;
   }
   size_t Station::getQuantity() const {
      return m_availQty;
   }
   void Station::updateQuantity() {
      if (m_availQty > 0) m_availQty--;
   }
   void Station::display(std::ostream& os, bool full) const {
      os << std::setfill('0') << std::setw(3)  
         << m_id << " | " << std::setfill(' ') << std::setw(m_widthField + 1) << std::left 
         << m_itemName  << " | " << std::right << std::setw(6) << std::setfill('0') 
         << m_serialNum << " | " << std::setfill(' ');

      if (full) {
         os << std::setw(4) << m_availQty << " | " << m_desc;
      }
      os << std::endl;
   }
}

