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

}