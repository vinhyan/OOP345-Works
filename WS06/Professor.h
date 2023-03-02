/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete:
*/

#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H

#include <string>
#include "Employee.h"

namespace sdds {
   class Professor : public Employee {
      std::string m_department;
   public:
      Professor(std::istream& in);
      void display(std::ostream& out) const;
      std::string status() const;
      std::string department() const;
   };

}



#endif // !SDDS_PROFESSOR_H
