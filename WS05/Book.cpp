#include <iomanip>
#include "Book.h"
#include "Utils.h"


using namespace std;
namespace sdds {
   Book::Book() {}
   const std::string& Book::title() const {
      return m_title;
   }
   const std::string& Book::country() const {
      return m_pubCountry;
   }
   const size_t& Book::year() const {
      return m_pubYear;
   }
   double& Book::price() {
      return m_price;
   }
   Book::Book(const std::string& strBook) {
      string str = strBook;
      extractToken(str, m_author, ',');
      extractToken(str, m_title, ',');
      extractToken(str, m_pubCountry, ',');
      extractToken(str, m_price, ',');
      extractToken(str, m_pubYear, ',');
      extractToken(str, m_desc, '\n');  // what could be the default delimeter?
   }

   std::ostream& Book::display(std::ostream& ostr) const {
      ostr << setw(20) << right << m_author << " | "
           << setw(22) << right << m_title <<  " | "
           << setw(5)  << right << m_pubCountry << " | "
           << setw(4)  << m_pubYear << " | ";
      ostr.setf(ios::fixed);
      ostr.precision(2);
      ostr << setw(6)  << right << m_price << " | "
           << m_desc << endl;
      return ostr;
   }

   Book::~Book() {}

   std::ostream& operator<<(std::ostream& ostr, const Book& book) {
      return book.display(ostr);
   }

}