// Name: Vinh Nhan
// Seneca Student ID: 171452212
// Seneca email: vnhan1@myseneca.ca
// Date of completion: 
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>

namespace sdds {
   class Station {
      int m_id;
      std::string m_itemName;
      std::string m_desc;
      size_t m_serialNum;
      size_t m_availQty;
      static size_t m_widthField;
      static int m_id_generator;
   public:
      Station(const std::string& record);
      const std::string& getItemName() const;
      size_t getNextSerialNumber();
      size_t getQuantity() const;
      void updateQuantity();
      void display(std::ostream& os, bool full) const;
      

   };


}





#endif // !SDDS_STATION_H
