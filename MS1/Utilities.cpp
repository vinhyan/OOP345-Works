// Name: Vinh Nhan
// Seneca Student ID: 171452212
// Seneca email: vnhan1@myseneca.ca
// Date of completion: Mar 1, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace sdds {
   char Utilities::m_delimiter = ',';

   Utilities::Utilities() {}

   void Utilities::setFieldWidth(size_t newWidth) {
      m_widthField = newWidth;
   }

   size_t Utilities::getFieldWidth() const {
      return m_widthField;
   }

   std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
      //1. extract token using m_delimeter, start from next_pos
      // a. find the pos of m_delimeter in the string (using find())
      std::string result;
      std::string newStr = str.substr(next_pos);
      size_t delim_pos = newStr.find(m_delimiter);
      
      // b. if delim found, extract token accordingly
      if (delim_pos != std::string::npos) {
         if (newStr[delim_pos] == str[next_pos]) {
            more = false;
            throw "ERROR! TOKEN CONTAINS DELIMITER";
         }
         else {
            result = newStr.substr(0, delim_pos);
            //update next_pos with the position of the next token
            next_pos += result.length() + 1;
            more = true;
         }
      }
      else {
         result = newStr;
         more = false;
      }
      // c. trim spaces
      trim(result);

      if (m_widthField < result.length()) m_widthField = result.length();

      return result;
   }

   void Utilities::setDelimiter(char newDelimiter) {
      m_delimiter = newDelimiter;
   }

   char Utilities::getDelimiter() {
      return m_delimiter;
   }

   Utilities::~Utilities() {}

   void trim(std::string& str) {
      size_t firstPos = str.find_first_not_of(" \f\n\r\t\v");
      str.erase(0, firstPos);
      size_t lastPos = str.find_last_not_of(" \f\n\r\t\v");
      str.erase(lastPos + 1);
   }


}

