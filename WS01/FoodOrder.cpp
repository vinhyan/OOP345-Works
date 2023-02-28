/* OOP345 Workshop 1
Full name: Vinh Nhan
Email: vnhan1@myseneca.ca
Student ID: 171452212
Date complete: 01/20/2023
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "foodorder.h"


double g_taxrate{};
double g_dailydiscount{};
using namespace std;
namespace sdds {
   FoodOrder::FoodOrder() {
      m_custName[0] = '\0';
      m_foodDesc = nullptr;
      m_price = 0;
      m_special = 0;
   }
   FoodOrder::FoodOrder(const FoodOrder& F) {
      *this = F;
   }

   FoodOrder& FoodOrder::operator=(const FoodOrder& F) {
      if (this != &F) {
         if (F.m_custName && F.m_custName[0] != '\0') {
            strcpy(m_custName, F.m_custName);
            delete[] m_foodDesc;
            m_foodDesc = new char[strlen(F.m_foodDesc) + 1];
            strcpy(m_foodDesc, F.m_foodDesc);
            m_price = F.m_price;
            m_special = F.m_special;
         }
      }
      return *this;
   }

   void FoodOrder::read(std::istream& istr) {
      char special{};
      string tmp{};
      if (!istr.fail()) {
         istr.getline(m_custName, 10, ',');
         getline(istr, tmp, ',');
         delete[] m_foodDesc;
         m_foodDesc = new char[tmp.length() + 1];
         strcpy(m_foodDesc, tmp.c_str());
         istr >> m_price;
         istr.get();
         istr >> special;

         if (special == 'Y') {
            m_special = true;
         }
         else {
            m_special = false;
         }
      }
   }

   void FoodOrder::display() const {
      static int i = 1;
      double priceTaxInc{};
      cout.width(2);
      cout.setf(ios::left);
      cout << i;
      cout.unsetf(ios::left);
      cout << ". ";

      if (m_custName && m_custName[0] != '\0') {
         priceTaxInc = m_price * (1 + g_taxrate);
         cout.width(10);
         cout.setf(ios::left);
         cout << m_custName << "|";
         cout.width(25);
         cout << m_foodDesc << "|";
         cout.width(12);
         cout.setf(ios::fixed);
         cout.precision(2);
         cout << priceTaxInc << "|";
         cout.unsetf(ios::left);
         
         if (m_special) {
            cout.width(13); 
            cout << priceTaxInc - g_dailydiscount;
         } 
      }
      else {
         cout << "No Order";
      }
      
      cout << endl;
      i++;
      
   }

   FoodOrder::~FoodOrder() {
      delete [] m_foodDesc;
   }
}