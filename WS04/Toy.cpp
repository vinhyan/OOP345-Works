/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 4
Date complete: Feb 11, 2023
*/
#include <iostream>
#include <iomanip>
#include "Toy.h"


using namespace std;
namespace sdds {

   Toy::Toy() {}

   void Toy::update(int numItems) {
      m_numItems = numItems;
   }

   Toy::Toy(const std::string& toy) {
      std::string tmp = toy;
      extractToken(tmp, m_orderID, ':');
      extractToken(tmp, m_name, ':');
      extractToken(tmp, m_numItems, ':');
      extractToken(tmp, m_price, ':');
   }

   std::ostream& Toy::display(std::ostream& ostr) const {
      double subtotal = m_price * m_numItems;
      double taxAmount = subtotal * 0.13;
      
      ostr << "Toy" << setw(8) << m_orderID << ": " 
           << setw(18) << right << m_name
           << setw(3) << m_numItems << " items" 
           << setw(8) << m_price << "/item "; 
      ostr.setf(ios::fixed);
      ostr.precision(2);
      ostr << " subtotal:" << setw(7) << subtotal 
           << " tax:" << setw(6) << taxAmount 
           << " total:" << setw(7) << subtotal + taxAmount << endl;
      return ostr;
   }

   Toy::~Toy() {}


   void extractToken(std::string& str, std::string& token, char delim) {
      size_t pos = str.find(delim);
      if (pos == string::npos) {
         token = str;
      }
      else {
         token = str.substr(0, pos);
         trim(token);
         str.erase(0, pos + 1);
      }
   }

   void extractToken(std::string& str, unsigned int& token, char delim) {
      size_t pos = str.find(delim);
      if (pos == string::npos) {
         token = stoi(str);
      }
      else {
         token = stoi(str.substr(0, pos));
         str.erase(0, pos + 1);
      }
   }

   void extractToken(std::string& str, double& token, char delim) {
      size_t pos = str.find(delim);
      if (pos == string::npos) {
         token = stod(str);
      }
      else {
         token = stod(str.substr(0, pos));
         str.erase(0, pos + 1);
      }
   }

   void trim(std::string& str) {
      while (isspace(str[0])) str.erase(0, 1);
      while (isspace(str[str.length() - 1])) str.erase(str.length() - 1);
   }

   std::ostream& operator<<(std::ostream& ostr, const Toy& toy) {
      return toy.display(ostr);
   }

}