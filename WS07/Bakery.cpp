/*
Name: Vinh Nhan
Student ID: 171452212
Date complete: Mar 19, 2023
Workshop 7
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "Bakery.h"

using namespace std;
namespace sdds {

   BakedGood::BakedGood(std::istream& istr) {
      string type{};
      string tmp{};
      istr >> type;

      bakedType = type == "Bread" ? BakedType::BREAD : BakedType::PASTERY;

      while (istr >> tmp && istr.tellg() != 29)  //desc stops at pos 29
         m_desc += " " + tmp; //need to trim !!
      
      streampos cur_pos = istr.tellg();
      istr.seekg(cur_pos -= 1); //go back to one pos to read shelflife and the rest

      istr >> m_shelfLife;
      istr >> m_stockQty;
      istr >> m_price;
   }

   Bakery::Bakery(const char* filename) {
      ifstream file(filename);
      string tmp{}; 

      if (file.is_open()) {
         while (getline(file, tmp)) {
            stringstream ss(tmp);
            BakedGood tmp_B(ss);
            m_bakedGood.push_back(tmp_B);
         }
      }
      else {
         throw "ERROR! INCORRECT FILENAME!";
      }
   }

   void Bakery::showGoods(std::ostream& os) const {
      for (auto it = m_bakedGood.begin(); it != m_bakedGood.end(); it++) {
         os << *it;
      }
   }

   std::ostream& operator<<(std::ostream& out, const BakedGood& b) {
       out << (b.bakedType == BakedType::BREAD ? "Bread" : "Pastry") << " - "
            << b.m_desc << " - "
            << b.m_shelfLife << " - "
            << b.m_stockQty << " - "
            << b.m_price << endl;
       return out;
   }

}