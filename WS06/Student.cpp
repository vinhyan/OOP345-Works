/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete: Mar 2, 2023
*/
#include <iomanip>
#include <sstream>
#include "Student.h"
#include "Utilities.h"

using namespace std;
namespace sdds {
   Student::Student() {}
   Student::Student(std::istream& istr) {
      string tmp{};
      string type{};
      //get type
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
      getline(istr, tmp, ',');
      trim(tmp);
      if (toupper(tmp[0]) == 'S') {
         m_id = tmp;
      }
      else {
         throw string(m_name + "++Invalid record!");
      }

      //get num of courses
      getline(istr, tmp, ',');
      trim(tmp);
      if (isNumberOnly(tmp)) {
         m_count = stoi(tmp);
      }
      else {
         throw string(m_name + "++Invalid record!");
      }

      m_courses = new string[m_count];

      //get courses array
      for (int i = 0; i < m_count; i++) {
         if (i != m_count - 1) {
            getline(istr, tmp, ',');
         }
         else {
            getline(istr, tmp);
         }
         m_courses[i] = trim(tmp);
      }
      
   }
   std::string Student::status() const {
      return string("Student");
   }
   std::string Student::name() const {
      return m_name;
   }
   std::string Student::age() const {
      return m_age;
   }
   std::string Student::id() const {
      return m_id;
   }
   void Student::display(std::ostream& out) const {
      out << "| " << left << setw(10) << "Student" << "| " << setw(10) << m_id << "| " << setw(20) << m_name << " | " << setw(3) << m_age << " |";
      for (int i = 0; i < m_count; i++) {
         out << m_courses[i] << (i != (m_count - 1) ? ", " : "");
      }
   }
   Student::~Student() {
      delete[] m_courses;
   }
}