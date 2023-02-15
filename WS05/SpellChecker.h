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
   class SpellChecker {
      std::string m_badWords[6]{};
      std::string m_goodWords[6]{};
      int m_foundCnt[6]{};
   public:
      SpellChecker();
      SpellChecker(const char* filename);
      void operator()(std::string& text);
      void showStatistics(std::ostream& out) const;
      ~SpellChecker();
   };


}




#endif // !SDDS_SPELLCHECKER_H
