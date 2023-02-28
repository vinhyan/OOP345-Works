/* OOP345 Workshop 1
Full name: Vinh Nhan
Email: vnhan1@myseneca.ca
Student ID: 171452212
Date complete: 01/20/2023
*/


#ifndef SDDS_FOOD_ORDER_H
#define SDDS_FOOD_ORDER_H


#include <iostream>


extern double g_taxrate;
extern double g_dailydiscount;
namespace sdds {
   class FoodOrder {
      char m_custName[10]{};
      char* m_foodDesc{};
      double m_price{};
      bool m_special{};
   public:
      FoodOrder();
      FoodOrder(const FoodOrder& F);
      FoodOrder& operator=(const FoodOrder& F);
      void read(std::istream& istr);
      void display() const;
      ~FoodOrder();

   };
}





#endif // !SDDS_FOOD_ORDER_H

