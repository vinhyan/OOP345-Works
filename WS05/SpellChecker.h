/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 5
Complete date: Feb 19, 2023
*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <string>

namespace sdds {
   const int ARR_SIZE = 6;
   class SpellChecker {
      std::string m_badWords[ARR_SIZE]{};
      std::string m_goodWords[ARR_SIZE]{};
      int m_foundCnt[ARR_SIZE]{};
   public:
      SpellChecker();
      SpellChecker(const char* filename);
      void operator()(std::string& text);
      void showStatistics(std::ostream& out) const;
      ~SpellChecker();
   };


}




#endif // !SDDS_SPELLCHECKER_H
