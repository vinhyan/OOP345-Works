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
         m_cnt = CO.m_cnt;
         delete[] m_toys;
         m_toys = nullptr;

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
         m_cnt = CO.m_cnt;
         delete[] m_toys;
         m_toys = CO.m_toys;
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
         //create tmp with new memory including the extra toy's
         //copy current data to tmp
         //add new toy to the last memory added
         //delete current array
         //set the current array point to tmp

         for (; i < m_cnt && !found; i++) {
            found = m_toys[i] == &toy;
         }

         if (!found) {
            tmp = new const Toy * [++m_cnt]; 
            for (size_t j = 0; j < m_cnt - 1; j++) {
               tmp[j] = m_toys[j];
            }
            tmp[m_cnt - 1] = &toy;
            delete[] m_toys;
            m_toys = tmp;
         }
      }
      return *this;
   }

   ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
      const Toy** tmp{};
      bool found{};
      size_t i{};
      if (m_cnt) {

         for (; i < m_cnt && !found; i++) {
            found = m_toys[i] == &toy;
         }
         if (found) {
            for (; i < m_cnt-1; i++) {
               m_toys[i - 1] = m_toys[i];
            }
            tmp = new const Toy * [m_cnt--];
            for (size_t j = 0; j < m_cnt; j++) {
               tmp[j] = m_toys[j];
            }
            delete[] m_toys;
            m_toys = tmp;
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