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
      std::string m_name{};
      std::string m_age{};
      std::string m_id{};
      std::string* m_courses{};
      int m_count{};
   public:
      Student();
      Student(std::istream&);
      std::string status() const;
      std::string name() const;
      std::string age() const;
      std::string id() const;
      void display(std::ostream& out) const;
      Student& operator=(const Student& src) = delete;
      Student(const Student& src) = delete;
      Student& operator=(Student&& src) noexcept;
      Student(Student&& src) noexcept;
      virtual ~Student();
   };

}



#endif // !SDDS_STUDENT_H
