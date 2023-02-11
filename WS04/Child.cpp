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
      /* No need since this is a constructor, no previous data)
      delete[] m_toys;
      m_toys = nullptr;*/

      if (toys != nullptr) { 
         m_toys = new const Toy * [m_cnt];
         for (size_t i = 0; i < m_cnt; i++) {
            //second layer DMA
            m_toys[i] = new Toy(*toys[i]);
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
                  //delete m_toys[i]; ---------------> why do I not need to delete memory here?
                  m_toys[i] = new Toy(*C.m_toys[i]);
               }
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
         if (!C.m_name.empty()) {
            m_name = C.m_name;
            m_age = C.m_age;
            m_cnt = C.m_cnt;

            //for (size_t i = 0; i < m_cnt; i++) { -----------> why no need to delete memory of each pointer in the array?
            //   delete m_toys[i];
            //}
            
           /* for (size_t i = 0; i < m_cnt; i++) {
               delete m_toys[i];
            }*/
            delete[] m_toys;
            m_toys = C.m_toys;
            //for (size_t i = 0; i < m_cnt; i++) {
            //   /*delete[] m_toys[i];*/
            //   m_toys[i] = C.m_toys[i];
            //}
            /*m_toys = C.m_toys;*/

            C.m_name = "";
            C.m_age = 0;
            C.m_cnt = 0;
            //make all members of src nullptr too??
            /*for (size_t i = 0; i < m_cnt; i++) { ----------> why do we not need to make each pointer in the array nullptr ??
               like this: C.m_toys[i] = nullptr;
            }*/
            C.m_toys = nullptr;
         }
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