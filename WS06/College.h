/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete:
*/

#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H
#include <vector>
#include "Person.h"

namespace sdds {
   class College {
      std::vector<Person*> m_persons;
   public:
      College() {};
      College(const College& src) = delete;
      College& operator=(const College& src) = delete;
      College& operator+=(Person* thePerson);
      void display(std::ostream& out) const;
      ~College() {};

   };

}




#endif // !SDDS_COLLEGE_H
