/*
Name: Vinh Nhan
Student ID: 171452212
Date complete: Mar 19, 2023
Workshop 7
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include "Bakery.h"

using namespace std;
namespace sdds {
   BakedGood::BakedGood() {}
   BakedGood::BakedGood(std::istream& istr) {
      string tmp{};
      istr >> tmp;

      bakedType = tmp == "Bread" ? BakedType::BREAD : BakedType::PASTERY;

      while (istr >> tmp && istr.tellg() != 29)  //desc stops at pos 29
         m_desc += " " + tmp;
      trim(m_desc);
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
      for_each(m_bakedGood.begin(), m_bakedGood.end(), [&os](const BakedGood& bg) {
            os << bg << endl;
         });

      int totalStock = accumulate(m_bakedGood.begin(), m_bakedGood.end(), (int)0, 
                       [](int total, const BakedGood& bakedGood) {
                           return total + bakedGood.m_stockQty;
                       });

      double totalPrice = accumulate(m_bakedGood.begin(), m_bakedGood.end(), (double)0, 
                          [](double total, const BakedGood& bakedGood) {
                              return total + bakedGood.m_price;
                          });

      os << "Total Stock: " << totalStock << endl
         << "Total Price: " << totalPrice << endl;
   }

   void Bakery::sortBakery(const char* field) {

      sort(m_bakedGood.begin(), m_bakedGood.end(), [field](const BakedGood& bg1, const BakedGood& bg2) {
         bool result{};
         if (field == "Description") {
            result = bg1.m_desc < bg2.m_desc;
         }
         else if (field == "Shelf") {
            result = bg1.m_shelfLife < bg2.m_shelfLife;
         }
         else if (field == "Stock") {
            result = bg1.m_stockQty < bg2.m_stockQty;
         }
         else if (field == "Price") {
            result = bg1.m_price < bg2.m_price;
         }
         else {
            throw "ERROR! INVALID FIELD NAME!";
         }
         return result;
         });
   }

   std::vector<BakedGood> Bakery::combine(const Bakery& B) {
      this->sortBakery("Price");
      
      vector<BakedGood> combinedB(m_bakedGood.size() + B.m_bakedGood.size());
      merge(m_bakedGood.begin(), m_bakedGood.end(), 
            B.m_bakedGood.begin(), B.m_bakedGood.end(), 
            combinedB.begin(), 
            [](const BakedGood& bg1, const BakedGood& bg2) { 
                  return bg1.m_price < bg2.m_price;
            });

      return combinedB;
   }

   bool Bakery::inStock(const char* desc, BakedType type) const {
      return any_of(m_bakedGood.begin(), m_bakedGood.end(), 
                    [desc, type](const BakedGood& bg) {
                        return (bg.m_desc == desc && 
                                bg.bakedType == type && 
                                bg.m_stockQty > 0);
                    });
   }

   std::list<BakedGood> Bakery::outOfStock(const BakedType type) const {
      list<BakedGood>outOfStock(m_bakedGood.size());
      auto it = copy_if(m_bakedGood.begin(), m_bakedGood.end(), outOfStock.begin(),
              [type](const BakedGood& bg) {
                  return (bg.bakedType == type && !bg.m_stockQty);
              });
      outOfStock.resize(distance(outOfStock.begin(), it));
      return outOfStock;
   }

   std::ostream& operator<<(std::ostream& out, const BakedGood& b) {
      out << "* " << setw(10) << left
         << (b.bakedType == BakedType::BREAD ? "Bread" : "Pastry") << " * "
         << setw(20)
         << b.m_desc << " * "
         << setw(5)
         << b.m_shelfLife << " * "
         << setw(5)
         << b.m_stockQty << " * "
         << setw(8) << right << fixed << setprecision(2)
         << b.m_price << " *";
       return out;
   }

   std::string& trim(std::string& str) {
      size_t firstPos = str.find_first_not_of(" \f\n\r\t\v");
      str.erase(0, firstPos);
      size_t lastPos = str.find_last_not_of(" \f\n\r\t\v");
      str.erase(lastPos + 1);
      return str;
   }

}