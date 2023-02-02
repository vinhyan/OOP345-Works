#ifndef SDDS_SCCOLLECTION_H
#define SDDS_SCCOLLECTION_H

#include <iostream>
#include "Pair.h"

namespace sdds {
   template <class T, unsigned int CAPACITY>
   class Collection {
      T m_arr[CAPACITY]{};
      unsigned int m_cnt{};
      static T m_dummy;
   public:
      unsigned int size() const {
         return m_cnt;
      }

      void display(std::ostream& ostr = std::cout) const {
         ostr << "----------------------\n"
            << "| Collection Content |\n"
            << "----------------------\n";
         for (unsigned int i = 0; i < m_cnt; i++) {
            ostr << m_arr[i] << std::endl;
         }
         ostr << "----------------------\n";
      }

      virtual bool add(const T& item) {
         bool success = false;
         if (m_cnt < CAPACITY) {
            m_arr[m_cnt] = item;
            m_cnt++;
            success = true;
         }
         return success;
      }

      T& operator[](unsigned int idx) {
         return (idx >= 0 && idx < m_cnt) ? m_arr[idx] : m_dummy;
      }

      ~Collection() {};

   };
   //initalize static variable member
   template<class T, unsigned int CAPACITY>
   T Collection<T, CAPACITY>::m_dummy{};

   template<>
   Pair Collection<Pair, 100>::m_dummy("No Key", "No Value");
}
#endif // !SDDS_SCCOLLECTION_H