/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 3
Date complete: February 3, 2023
*/

#include <iomanip>
#include "Pair.h"

using namespace std;
namespace sdds {

   std::ostream& Pair::display(std::ostream& ostr) const {
      ostr << setw(20) << right << m_key << ": " << left << m_value;
      return ostr;
   }
   bool Pair::operator==(const Pair& P) {
      return m_key == P.m_key;
   }
   std::ostream& operator<<(std::ostream& ostr, const Pair& pair) {
      return pair.display(ostr);
   }
}

