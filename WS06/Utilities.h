/*
Name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 6
Date complete: Mar 2, 2023
*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "Person.h"

namespace sdds {
   Person* buildInstance(std::istream& in);
   std::string& trim(std::string& str);
   bool isNumberOnly(std::string& str);
}




#endif // !SDDS_UTILITIES_H
