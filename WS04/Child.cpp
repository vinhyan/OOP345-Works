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
      if (toys != nullptr) { 
         m_toys = new const Toy * [m_cnt];
         for (size_t i = 0; i < m_cnt; i++) {
            //second layer DMA
            m_toys[i] = new Toy(*(toys[i]));
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
         //remove memory of 2 layers from the current obj 
         for (size_t i = 0; i < m_cnt; i++) {
            delete m_toys[i];
            m_toys[i] = nullptr;
         }
         delete[] m_toys;
         m_toys = nullptr;

         //copy data from src to the current obj (deep copy)
         if (C.m_toys) {
            m_name = C.m_name;
            m_age = C.m_age;
            m_cnt = C.m_cnt;
            m_toys = new const Toy * [m_cnt];
            for (size_t i = 0; i < m_cnt; i++) {
               m_toys[i] = new Toy(*C.m_toys[i]);
            }
         }
      }
      return *this;
   }

   Child::Child(Child&& C) noexcept {
      *this = move(C);
   }

   Child& Child::operator=(Child&& C) noexcept {
      if (this != &C) {
         //remove memory of 2 layers from the current obj 
         for (size_t i = 0; i < m_cnt; i++) {
            delete m_toys[i];
            m_toys[i] = nullptr;
         }
         delete[] m_toys;
         m_toys = nullptr;

         //copy data from src to the current obj
         if (C.m_toys) {
            m_name = C.m_name;
            m_age = C.m_age;
            m_cnt = C.m_cnt;
            m_toys = C.m_toys;
         }
         
         //set data from src to 0
         C.m_name = "";
         C.m_age = 0;
         C.m_cnt = 0;
         C.m_toys = nullptr;
      }
      return *this;
   }

   std::ostream& Child::display(std::ostream& ostr) const {
      static int i = 1;
      ostr << "--------------------------\n" 
              << "Child " << i << ": " << m_name << " " << m_age << " years old:\n"
              << "--------------------------\n";
      if (m_cnt) {
         for (size_t i = 0; i < m_cnt; i++) {
            m_toys[i]->display(ostr);
         }
      }
      else {
         ostr << "This child has no toys!\n";
      }
      ostr << "--------------------------\n";
      i++;
      return ostr;
   }

   Child::~Child() {
      //delete 2 layers
      for (size_t i = 0; i < m_cnt; i++) {
         delete m_toys[i];
      }
      delete[] m_toys;
   }

   std::ostream& operator<<(std::ostream& ostr, const Child& C) {
      return C.display(ostr);
   }

}