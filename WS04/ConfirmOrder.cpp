/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 4
Date complete: Feb 11, 2023
*/
#include <iostream>
#include "ConfirmOrder.h"


using namespace std;
namespace sdds {

   ConfirmOrder::ConfirmOrder() {}

   ConfirmOrder::ConfirmOrder(const ConfirmOrder& CO){
      *this = CO;
   }

   ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& CO) {
      if (this != &CO) {
         //remove memory from current obj
         delete[] m_toys;
         m_toys = nullptr;

         //copy data from src (deep copy)
         m_cnt = CO.m_cnt;
         if (CO.m_toys != nullptr) {
            m_toys = new const Toy * [m_cnt];
            for (size_t i = 0; i < m_cnt; i++) {
               m_toys[i] = CO.m_toys[i];
            }
         }
      }
      return *this;
   }

   ConfirmOrder::ConfirmOrder(ConfirmOrder&& CO) noexcept {
      *this = move(CO);
   }

   ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& CO) noexcept {
      if (this != &CO) {
         //remove data from current obj
         delete[] m_toys;
         //copy data from src
         m_cnt = CO.m_cnt;
         m_toys = CO.m_toys;
         //set data from src to 0
         CO.m_cnt = 0;
         CO.m_toys = nullptr;
      }
      return *this;
   }

   ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
      const Toy** tmp{};
      bool found{};
      size_t i{};
      if (!m_cnt) {
         m_toys = new const Toy*[++m_cnt]; // use ++m_cnt instead of m_cnt++ to avoid allocating new size prematurely (before increasing)
         m_toys[m_cnt-1] = &toy;
      }
      else {
         for (; i < m_cnt && !found; i++) {  //check if toy exists
            found = m_toys[i] == &toy;
         }
         if (!found) {  //only add if does not exist
            tmp = new const Toy * [++m_cnt];  //create tmp with new memory 
            for (size_t j = 0; j < m_cnt - 1; j++) {  //copy current data to tmp
               tmp[j] = m_toys[j];
            }
            tmp[m_cnt - 1] = &toy; //add new toy to the last memory 
            delete[] m_toys;  //delete current array
            m_toys = tmp;  //set the current array point to tmp
         }
      }
      return *this;
   }

   ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
      const Toy** tmp{};
      bool found{};
      size_t i{};
      if (m_cnt) { 
         for (; i < m_cnt && !found; i++) {  //check if toy toy exists
            found = m_toys[i] == &toy;
         }
         if (found) {  //only remove if exists
            for (; i < m_cnt-1; i++) {  //remove by shifting elements up from the found toy
               m_toys[i - 1] = m_toys[i];
            }
            tmp = new const Toy * [--m_cnt];  //tmp with new memory
            for (size_t j = 0; j < m_cnt; j++) {
               tmp[j] = m_toys[j];  //copy current data to tmp
            }
            delete[] m_toys;  //delete current array
            m_toys = tmp;  //set the current array point to tmp
         }
      }
      return *this;
   }

   std::ostream& ConfirmOrder::display(std::ostream& ostr) const {
      ostr << "--------------------------\n"
           << "Confirmations to Send\n"
           << "--------------------------\n";
      if (m_cnt) {
         for (size_t i = 0; i < m_cnt; i++) {
            m_toys[i]->display(ostr);
         }
      }
      else {
         ostr << "There are no confirmations to send!\n"; 
      }
      ostr << "--------------------------\n";
      return ostr;
   }

   ConfirmOrder::~ConfirmOrder() {
      delete[] m_toys;
   }

   std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& CO) {
      return CO.display(ostr);
   }

}