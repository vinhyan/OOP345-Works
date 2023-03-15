/*
Name: Vinh Nhan
Student ID: 171452212
Date complete: Mar 19, 2023
Workshop 7
*/


#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <iostream>
#include <string>
#include <vector>
#include <list>


namespace sdds {
   enum class BakedType {
      BREAD, PASTERY
   };

   struct BakedGood {
      BakedType bakedType{};
      std::string m_desc{};
      size_t m_shelfLife{};
      size_t m_stockQty{};
      double m_price{};
      BakedGood();
      BakedGood(std::istream& istr);
   };

   class Bakery {
      std::vector<BakedGood> m_bakedGood{};
   public:
      Bakery(const char* filename);
      void showGoods(std::ostream& os) const;
      void sortBakery(const char* field);
      std::vector<BakedGood> combine(const Bakery& B);
      bool inStock(const char* desc, BakedType type) const;
      std::list<BakedGood> outOfStock(const BakedType type) const;
      
   };

   std::ostream& operator<<(std::ostream& out, const BakedGood& b);

   std::string& trim(std::string& str);



}




#endif // !SDDS_BAKERY_H

