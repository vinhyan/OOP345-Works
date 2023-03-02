/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete: Mar 2, 2023
*/

#include "Professor.h"
#include "Utilities.h"

using namespace std;
namespace sdds {
   Professor::Professor(std::istream& in) : Employee(in) {
      string tmp{};
      getline(in, tmp, ',');
      m_department = trim(tmp);

   }
   void Professor::display(std::ostream& out) const{
      Employee::display(out);
      out << m_department << "|" << " Professor";
   }
   std::string Professor::status() const {
      return string("Professor");
   }
   std::string Professor::department() const {
      return m_department;
   }
   //Person* Professor::clone() const {
   //   return new Professor(*this);
   //}
}

