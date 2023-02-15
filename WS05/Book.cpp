/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 5
Complete date: Feb 19, 2023
*/

#include <iomanip>
#include "Book.h"


using namespace std;
namespace sdds {
   Book::Book() {}
   const std::string& Book::title() const {
      return m_title;
   }
   const std::string& Book::country() const {
      return m_pubCountry;
   }
   const size_t& Book::year() const {
      return m_pubYear;
   }
   double& Book::price() {
      return m_price;
   }
   Book::Book(const std::string& strBook) {
      string str = strBook;
      extractToken(str, m_author, ',');
      extractToken(str, m_title, ',');
      extractToken(str, m_pubCountry, ',');
      extractToken(str, m_price, ',');
      extractToken(str, m_pubYear, ',');
      extractToken(str, m_desc, '\n');  // what could be the default delimeter?
   }

   std::ostream& Book::display(std::ostream& ostr) const {
      ostr << setw(20) << right << m_author << " | "
           << setw(22) << right << m_title <<  " | "
           << setw(5)  << right << m_pubCountry << " | "
           << setw(4)  << m_pubYear << " | ";
      ostr.setf(ios::fixed);
      ostr.precision(2);
      ostr << setw(6)  << right << m_price << " | "
           << m_desc << endl;
      return ostr;
   }

   Book::~Book() {}

   //helper functions

   std::ostream& operator<<(std::ostream& ostr, const Book& book) {
      return book.display(ostr);
   }

   
   void extractToken(std::string& str, std::string& token, char delim) {
      size_t pos = str.find(delim);
      if (pos == string::npos) {
         token = str;
         trim(token);
      }
      else {
         token = str.substr(0, pos);
         trim(token);
         str.erase(0, pos + 1);
      }
   }

   void extractToken(std::string& str, size_t& token, char delim) {
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
      size_t firstPos = str.find_first_not_of(" \f\n\r\t\v");
      str.erase(0, firstPos);
      size_t lastPos = str.find_last_not_of(" \f\n\r\t\v");
      str.erase(lastPos + 1);
   }

}