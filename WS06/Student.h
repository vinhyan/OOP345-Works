/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete: Mar 2, 2023
*/

#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

#include <iostream>
#include <string>
#include "Person.h"

namespace sdds {
   class Student : public Person {
      std::string m_name;
      std::string m_age; //string or int??
      std::string m_id;
      std::string* m_courses;
      int m_count;
   public:
      Student(std::istream&);
      std::string status() const;
      std::string name() const;
      std::string age() const;
      std::string id() const;
      //int courseCount() const;
      //Person* clone() const;
      void display(std::ostream& out) const;
      //std::string* courses() const;
      ~Student();
   };

}



#endif // !SDDS_STUDENT_H