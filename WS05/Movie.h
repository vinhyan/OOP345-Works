/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 5
Complete date: Feb 19, 2023
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>

namespace sdds {
   class Movie {
      std::string m_title{};
      size_t m_year{};
      std::string m_desc{};
   public:
      Movie();
      const std::string& title() const;
      Movie(const std::string& strMovie);
      std::ostream& display(std::ostream& ostr) const;
      template<typename T>
      void fixSpelling(T& spellChecker) {
         spellChecker(m_title);
         spellChecker(m_desc);
      }
      ~Movie();

   };


   //helper functions
   std::ostream& operator<<(std::ostream& ostr, const Movie& movie);

   void extractToken(std::string& str, std::string& token, char delim);
   void extractToken(std::string& str, size_t& token, char delim);
   void extractToken(std::string& str, double& token, char delim);
   void trim(std::string& str);

}



#endif // !SDDS_MOVIE_H
