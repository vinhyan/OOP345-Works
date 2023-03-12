/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete: Mar 2, 2023
*/

#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H

#include <string>
#include "Person.h"
#include "Employee.h"

namespace sdds {
   class Professor : public Employee {
      std::string m_department{};
   public:
      Professor();
      Professor(std::istream& in);
      void display(std::ostream& out) const;
      std::string status() const;
      std::string department() const;
      virtual ~Professor();
   };

}



#endif // !SDDS_PROFESSOR_H
