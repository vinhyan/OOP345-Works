/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete: Mar 2, 2023
*/

#include <iomanip>
#include "Employee.h"
#include "Utilities.h"


using namespace std;
namespace sdds {
   Employee::Employee() {}
   Employee::Employee(std::istream& istr) {
      string tmp{};
      string type{};
      getline(istr, type, ',');

      //get name
      getline(istr, tmp, ',');
      m_name = trim(tmp);

      //get age
      getline(istr, tmp, ',');
      trim(tmp);
      if (isNumberOnly(tmp)) {        
         m_age = tmp;
      }
      else {
         throw string(m_name + "++Invalid record!");
      }

      //get id
      //   check if this is an Employee or a Professor to determine delimiter
      if (toupper(type[0]) == 'E') {
         getline(istr, tmp);
      }
      else {
         getline(istr, tmp, ',');
      }

      trim(tmp);
      if (toupper(tmp[0]) == 'E') {
         m_id = tmp;
      }
      else {
         throw string(m_name + "++Invalid record!");
      }
   }

   std::string Employee::status() const {
      return "Employee";
   }

   std::string Employee::name() const {
      return m_name;
   }

   std::string Employee::age() const {
      return m_age;
   }

   std::string Employee::id() const {
      return m_id;
   }

   void Employee::display(std::ostream& os) const {
      os << "| " << left << setw(10) 
         << "Employee" << "| " << setw(10) 
         << m_id << "| " << setw(20) 
         << m_name << " | " << setw(3) 
         << m_age << " |";
   }

   Employee::~Employee() {}

}