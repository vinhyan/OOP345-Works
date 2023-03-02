/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete:
*/
#include <iostream>
#include <string>
#include <sstream>
#include "Utilities.h"
#include "Employee.h"
#include "Professor.h"
#include "Student.h"

using namespace std;
namespace sdds {
   Person* buildInstance(std::istream& in) {
      Person* person{};
      string tmp{};

      getline(in, tmp);
      stringstream ss(tmp);
      char type = toupper(tmp[0]);

      if (type == 'E') {
         person = new Employee(ss);
      }
      else if (type == 'P') {
         person = new Professor(ss);
      }
      else if (type == 'S') {
         person = new Student(ss);
      }
      else {
         person = nullptr;
      }
      return person;
   }

   bool isNumberOnly(std::string& str) {
      bool valid = true;
      for (size_t i = 0; i < str.length() && valid; i++) {
         if (!isdigit(str[i])) valid = false;
      }
      return valid;
   }

   std::string& trim(std::string& str) {
      size_t firstPos = str.find_first_not_of(" \f\n\r\t\v");
      str.erase(0, firstPos);
      size_t lastPos = str.find_last_not_of(" \f\n\r\t\v");
      str.erase(lastPos + 1);
      return str;
   }

   void printCentre(const char* str, size_t lineLen, char fill) {
      size_t numOfSpaces = ((lineLen - 2) - strlen(str)) / 2;
      string wrapper(numOfSpaces, fill);
      cout << "| " << wrapper << str << wrapper << " | " << endl;
   }
}