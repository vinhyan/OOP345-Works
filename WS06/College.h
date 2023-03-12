/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete: Mar 2, 2023
*/

#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H
#include <vector>
#include <list>
#include "Person.h"

namespace sdds {
   class College {
      std::vector<Person*> m_persons{};
   public:
      College();
      College(const College& src) = delete;
      College& operator=(const College& src) = delete;
      College& operator+=(Person* thePerson);
      void display(std::ostream& out) const;

      template<class T>
      void select(const T& test, std::list<const Person*>& persons) {
         for (auto it = m_persons.begin(); it != m_persons.end(); it++) {
            if (test(*it)) persons.push_back(*it);
         }
      }
      ~College();
   };

}




#endif // !SDDS_COLLEGE_H
