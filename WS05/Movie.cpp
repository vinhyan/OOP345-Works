/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 5
Complete date: Feb 19, 2023
*/
#include <iomanip>
#include "Movie.h"


using namespace std;
namespace sdds {
   Movie::Movie() {}

   const std::string& Movie::title() const {
      return m_title;
   }

   Movie::Movie(const std::string& strMovie) {
      string str = strMovie;
      extractToken(str, m_title, ',');
      extractToken(str, m_year, ',');
      extractToken(str, m_desc, '\n');
   }

   std::ostream& Movie::display(std::ostream& ostr) const {
      ostr << setw(40) << right << m_title << " | "
           << setw(4) << m_year << " | " << m_desc << endl;
      return ostr;
   }

   Movie::~Movie() {}

   //helper functions

   std::ostream& operator<<(std::ostream& ostr, const Movie& movie) {
      return movie.display(ostr);
   }

   //void extractToken(std::string& str, std::string& token, char delim) {
   //   size_t pos = str.find(delim);
   //   if (pos == string::npos) {
   //      token = str;
   //      trim(token);
   //   }
   //   else {
   //      token = str.substr(0, pos);
   //      trim(token);
   //      str.erase(0, pos + 1);
   //   }
   //}

   //void extractToken(std::string& str, size_t& token, char delim) {
   //   size_t pos = str.find(delim);
   //   if (pos == string::npos) {
   //      token = stoi(str);
   //   }
   //   else {
   //      token = stoi(str.substr(0, pos));
   //      str.erase(0, pos + 1);
   //   }
   //}

   //void extractToken(std::string& str, double& token, char delim) {
   //   size_t pos = str.find(delim);
   //   if (pos == string::npos) {
   //      token = stod(str);
   //   }
   //   else {
   //      token = stod(str.substr(0, pos));
   //      str.erase(0, pos + 1);
   //   }
   //}

   //void trim(std::string& str) {
   //   size_t firstPos = str.find_first_not_of(" \f\n\r\t\v");
   //   str.erase(0, firstPos);
   //   size_t lastPos = str.find_last_not_of(" \f\n\r\t\v");
   //   str.erase(lastPos + 1);
   //}



}