/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete: Mar 2, 2023
*/
#include <iomanip>
#include <string>
#include "College.h"
#include "Utilities.h"
#include "Professor.h"
#include "Student.h"


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
         out << std::endl;
      }

      out << "------------------------------------------------------------------------------------------------------------------------\n";
      out << "|                                        Test #2 Persons in the college!                                               |\n";
      out << "------------------------------------------------------------------------------------------------------------------------\n";
      

      for (auto it = m_persons.begin(); it != m_persons.end(); it++) {
         out << "| " << std::left << std::setw(10) 
             << (*it)->status() << "| " << std::setw(10) 
             << (*it)->id() << "| " << std::setw(20) 
             << (*it)->name() << " | " << std::setw(3) 
             << (*it)->age() << " |\n";
    /*     Person* clone = (*it)->clone();
         if (clone->status() == "Professor") {
            out << static_cast<Professor*>(clone)->department() << "|" 
                << static_cast<Professor*>(clone)->status() << std::endl;
         }
         else if (clone->status() == "Student") {
            int course_cnt = static_cast<Student*>(clone)->courseCount();
            for (int i = 0; i < course_cnt; i++) {
               out << static_cast<Student*>(clone)->courses()[i] << (i != (course_cnt - 1) ? ", " : "\n");
            }
         }
         else {
            std::cout << std::endl;
         }*/
      }

      out << "------------------------------------------------------------------------------------------------------------------------\n";
        
   }
   College::~College() {
      for (auto it = m_persons.begin(); it != m_persons.end(); it++) {
         delete *it;
      }
   }
}