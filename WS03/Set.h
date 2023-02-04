/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 3
Date complete: February 3, 2023
*/
#ifndef SDDS_SET_H
#define SDDS_SET_H

#include <iostream>
#include <cmath>
#include "Collection.h"


namespace sdds {
   template<class T>
   class Set : public Collection<T, 100> {
   public:
      Set() {};
      bool add(const T& item) {
         bool found = false;
         bool success = false;
         for (unsigned int i = 0; i < this->size() && !found; i++) {
            if ((*this)[i] == item) found = true;
         }

         if (!found) {
            success = Collection<T, 100>::add(item);
         }
         return success;
      }
      ~Set() {};
   };

   template<>
   inline bool Set<double>::add(const double& item) {
      bool found = false;
      bool success = false;
      for (unsigned int i = 0; i < this->size() && !found; i++) {
         if (std::fabs((*this)[i] - item) <= 0.01) found = true;
      }

      if (!found) {
         success = Collection<double, 100>::add(item);
      }
      return success;
   }


}
#endif // !SDDS_SET_H
