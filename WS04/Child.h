/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 4
Date complete: Feb 11, 2023
*/

#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H

#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds {
   class Child {
      std::string m_name{};
      int m_age{};
      const Toy** m_toys{}; // composition relationship. child owns toys 
      size_t m_cnt{};
   public:
      Child();
      Child(std::string name, int age, const Toy* toys[], size_t count);
      size_t size() const;
      Child(const Child& C);
      Child& operator=(const Child& C);
      Child(Child&& C) noexcept;
      Child& operator=(Child&& C) noexcept;
      std::ostream& display(std::ostream& ostr) const;
      ~Child();

   };

   std::ostream& operator<<(std::ostream& ostr, const Child& C);

}



#endif // !SDDS_CHILD_H
