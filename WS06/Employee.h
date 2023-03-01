/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete:
*/


#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H

#include <iostream>
#include <string>
#include "Person.h"

namespace sdds {
   class Employee : public Person {
      std::string m_name;
      std::string m_age;
      std::string m_id;
   public:
      Employee(std::istream& istr);
      std::string status() const;
      std::string name() const;
      std::string age() const;
      std::string id() const;
      void display(std::ostream&) const;
      ~Employee();
   };



}




#endif // !SDDS_EMPLOYEE_H