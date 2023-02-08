/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 4
Date complete: Feb 11, 2023
*/
#include "Child.h"

using namespace std;
namespace sdds {
   Child::Child() {}

   Child::Child(std::string name, int age, const Toy* toys[], size_t count) : m_name(name), m_age(age), m_cnt(count) {
      
      delete[] m_toys;
      m_toys = nullptr;

      if (toys != nullptr) {  // is this correct?
         m_toys = new const Toy * [m_cnt];
         for (size_t i = 0; i < m_cnt; i++) {
            m_toys[i] = toys[i];
         }
      }
   }

   size_t Child::size() const {
      return m_cnt;
   }

   Child::Child(const Child& C) {
      *this = C;
   }

   Child& Child::operator=(const Child& C) {
      if (this != &C) {
         if (!C.m_name.empty()) {
            m_name = C.m_name;
            m_age = C.m_age;
            m_cnt = C.m_cnt;

            delete[] m_toys;
            m_toys = nullptr;

            if (C.m_toys != nullptr) {
               m_toys = new const Toy * [m_cnt];
               for (size_t i = 0; i < m_cnt; i++) {
                  m_toys[i] = C.m_toys[i];
               }
            }
         }
      }
      return *this;
   }

   Child::Child(Child&& C) {
      *this = move(C);
   }

   Child& Child::operator=(Child&& C) {
      if (this != &C) {
         if (!C.m_name.empty()) {
            m_name = C.m_name;
            m_age = C.m_age;
            m_cnt = C.m_cnt;
            delete[] m_toys;
            m_toys = C.m_toys;

            C.m_name = "";
            C.m_age = 0;
            C.m_cnt = 0;
            C.m_toys = nullptr;
         }
      }
      
   }

   std::ostream& Child::display(std::ostream& ostr) const {
      static int i = 0;
      ostr << "--------------------------\n" 
              << "Child " << i << ": " << m_name << " " << m_age << " years old:\n"
              << "--------------------------\n";
      if (m_cnt) {
         ostr << "This child has no toys!\n";
      }
      else {
         for (size_t i = 0; i < m_cnt; i++) {
            m_toys[i]->display(ostr);
         }
      }
      ostr << "--------------------------\n";

   }

   Child::~Child() {
      delete[] m_toys;
   }

}