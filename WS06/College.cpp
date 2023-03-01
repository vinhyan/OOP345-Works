/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete:
*/
#include <iomanip>
#include <string>
#include "College.h"
#include "Utilities.h"


namespace sdds {
   College& College::operator+=(Person* thePerson) {
      m_persons.push_back(thePerson);
      return *this;
   }
   void College::display(std::ostream& out) const {

      out << "------------------------------------------------------------------------------------------------------------------------\n";
      out << "|                                        Test #1 Persons in the college!                                               |\n";
      out << "------------------------------------------------------------------------------------------------------------------------\n";

      for (auto it = m_persons.begin(); it != m_persons.end(); it++) {
         (*it)->display(out);
      }

      out << "------------------------------------------------------------------------------------------------------------------------\n";
      out << "|                                        Test #2 Persons in the college!                                               |\n";
      out << "------------------------------------------------------------------------------------------------------------------------\n";

      for (auto it = m_persons.begin(); it != m_persons.end(); it++) {
         out << "| " << std::left << std::setw(10) << (*it)->status() << "| " << std::setw(10) << (*it)->id() << "| " << std::setw(20) << (*it)->name() << " | " << std::setw(3) << (*it)->age() << " | \n";
      }

      out << "------------------------------------------------------------------------------------------------------------------------\n";
        
   }
}