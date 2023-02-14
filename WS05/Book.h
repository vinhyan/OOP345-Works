#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds {
   class Book {
      std::string m_author{};
      std::string m_title{};
      std::string m_pubCountry{};
      unsigned int m_pubYear{};
      double m_price{};
      std::string m_desc{};
   public:
      Book();
      const std::string& title() const;
      const std::string& country() const;
      const size_t& year() const;
      double& price();
      Book(const std::string& strBook);
      std::ostream& display(std::ostream& ostr) const;
      ~Book();

   };

   std::ostream& operator<<(std::ostream& ostr, const Book& book);




}



#endif // !SDDS_BOOK_H
