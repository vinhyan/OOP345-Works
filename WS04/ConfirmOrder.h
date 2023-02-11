/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 4
Date complete: Feb 11, 2023
*/
#ifndef SDDS_CONFIRM_ORDER_H
#define SDDS_CONFIRM_ORDER_H

#include <iostream>
#include "Toy.h"


namespace sdds {
   class ConfirmOrder {
      const Toy** m_toys{};   // Aggregration relationship
      size_t m_cnt{};
   public:
      ConfirmOrder();
      ConfirmOrder(const ConfirmOrder& CO);
      ConfirmOrder& operator=(const ConfirmOrder& CO);
      ConfirmOrder(ConfirmOrder&& CO) noexcept;
      ConfirmOrder& operator=(ConfirmOrder&& CO) noexcept;
      ConfirmOrder& operator+=(const Toy& toy);
      ConfirmOrder& operator-=(const Toy& toy);
      std::ostream& display(std::ostream& ostr) const;
      ~ConfirmOrder();
   };

   std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& CO);




}



#endif // !SDDS_CHILD_H

