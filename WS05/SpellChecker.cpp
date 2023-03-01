/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 5
Complete date: Feb 19, 2023
*/
#include <iomanip>
#include <fstream>
#include "SpellChecker.h"

using namespace std;
namespace sdds {
   SpellChecker::SpellChecker() {}
   SpellChecker::SpellChecker(const char* filename) {
      fstream inf(filename);
      string str{};

      if (inf) {
         for (int i = 0; i < ARR_SIZE; i++) {
            getline(inf, str);
            m_badWords[i] = str.substr(0, str.find_first_of(" \f\n\r\t\v"));
            m_goodWords[i] = str.substr(str.find_last_of(" \f\n\r\t\v") + 1);
          /*  if (!(i % 2)) {
               getline(inf, m_badWords[i]);
            }
            else {
               getline(inf, m_goodWords[i]);
            }*/
         }
      }
      else {
         throw "Bad file name!";
      }
   }
   void SpellChecker::operator()(std::string& text) {
      size_t pos{};
      for (int i = 0; i < ARR_SIZE; i++) {
         do {
            pos = text.find(m_badWords[i]);
            if (pos != std::string::npos) {
               text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
               m_foundCnt[i]++;
            }
         } while (pos != std::string::npos);
      }
   }
   void SpellChecker::showStatistics(std::ostream& out) const {
      cout << "Spellchecker Statistics" << endl;
      for (int i = 0; i < ARR_SIZE; i++) {
         cout << setw(15) << right << m_badWords[i] << ": " << m_foundCnt[i] << " replacements" << endl;
      }
   }

   SpellChecker::~SpellChecker() {};
}