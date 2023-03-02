// Name: Vinh Nhan
// Seneca Student ID: 171452212
// Seneca email: vnhan1@myseneca.ca
// Date of completion: Mar 2, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds {
   size_t CustomerOrder::m_widthField = 1;

   CustomerOrder::CustomerOrder(const CustomerOrder& src) {
      throw "ERROR! NOT ALLOWED";
   }

   CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
      *this = std::move(src);
   }

   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
      if (this != &src) {
         //delete
         for (auto i = 0u; i < m_cntItem; i++) {
            delete m_lstItem[i];
            m_lstItem[i] = nullptr;
         }
         delete[] m_lstItem;
         m_lstItem = nullptr;

         //shallow copy
         m_name = src.m_name;
         m_product = src.m_product;
         m_cntItem = src.m_cntItem;

         //deep copy
         if (src.m_lstItem) {
            m_lstItem = src.m_lstItem;
         }
         
         //remove src
         src.m_lstItem = nullptr;
         src.m_name = "";
         src.m_product = "";
         src.m_cntItem = 0;
      }
      return *this;
   }

   bool CustomerOrder::isOrderFilled() const {
      bool isFilled = true;
      for (auto i = 0u; i < m_cntItem && isFilled; i++) {
         isFilled = m_lstItem[i]->m_isFilled;
      }
      return isFilled;
   }

   bool CustomerOrder::isItemFilled(const std::string& itemName) const {    
      bool found = false;
      bool isFilled = true;
      bool status = true;
      for (auto i = 0u; i < m_cntItem && isFilled; i++) {  //exit loop immediately if a found item is NOT filled
         if (m_lstItem[i]->m_itemName == itemName) {
            isFilled = m_lstItem[i]->m_isFilled;
            found = true;
         }
      }
      //1. if nothing is found (found = false), status = true
      //2. if at least 1 item is found (found = true), but is NOT filled (isFilled = false), status = false
      //3. if item is found and is filled (found = true && isFilled = true), status = true
      if (found && !isFilled) {
         status = false;
      }
      return status;
   }

   void CustomerOrder::fillItem(Station& station, std::ostream& os) const {
      bool found = false;
      int i = 0;
      for (; i < m_cntItem && !found; i++) {
         found = station.getItemName() == m_lstItem[i]->m_itemName;
      }

      if (found && i--) {
         if (station.getQuantity() >= 1) {
            m_lstItem[i]->m_isFilled = true;
            m_lstItem[i]->m_serialNumber = station.getNextSerialNumber(); 
            station.updateQuantity();

            os << "    Filled " << m_name << ", " 
               << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
         }
      }
   }

   void CustomerOrder::display(std::ostream& os) const {
      os << m_name << " - " << m_product << std::endl;
      for (auto i = 0u; i < m_cntItem; i++) {
         os << "[" << std::setw(6) << std::setfill('0') 
            << m_lstItem[i]->m_serialNumber << "] " 
            << std::setw(m_widthField) << std::setfill(' ') << std::left 
            << m_lstItem[i]->m_itemName << " - "
            << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
      }
   }

   CustomerOrder::CustomerOrder(const std::string& str) {
      Utilities util;
      size_t next_pos{};
      bool more = true;

      m_name = util.extractToken(str, next_pos, more);
      m_product = util.extractToken(str, next_pos, more);

      //store the pos of the list of item from the string
      size_t itemList_pos = next_pos;

      //get number of item
      while (more) {
         util.extractToken(str, next_pos, more);
         m_cntItem++;
      }

      //Assign new memory to lstItem array, start extracting token again from itemList_pos
      more = true;
      m_lstItem = new Item * [m_cntItem];
      for (auto i = 0u; i < m_cntItem; i++) {
         m_lstItem[i] = new Item(util.extractToken(str, itemList_pos, more));
      }

      m_widthField = (m_widthField < util.getFieldWidth() ? util.getFieldWidth() : m_widthField);
   }

   CustomerOrder::~CustomerOrder() {
      for (auto i = 0u; i < m_cntItem; i++) {
         delete m_lstItem[i];
      }
      delete[] m_lstItem;
   }

}