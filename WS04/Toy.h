/*
Student name: Vinh Nhan
Student ID: 171452212
OOP345 Workshop 4
Date complete: Feb 11, 2023
*/
#ifndef SDDS_TOY_H
#define SDDS_TOY_H

#include <string>


namespace sdds {
   class Toy {
      unsigned int m_orderID{};
      std::string m_name{};
      unsigned int m_numItems{};
      double m_price{};

   public:
      Toy();
      void update(int numItems);
      Toy(const std::string& toy);
      std::ostream& display(std::ostream& ostr) const;
      ~Toy();
   };
   void extractToken(std::string& str, std::string& token, char delim);
   void extractToken(std::string& str, unsigned int& token, char delim);
   void extractToken(std::string& str, double& token, char delim);

   
   void trim(std::string& str);
   std::ostream& operator<<(std::ostream& ostr, const Toy& toy);

}



#endif // !SDDS_TOY_H
