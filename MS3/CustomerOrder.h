// Name: Vinh Nhan
// Seneca Student ID: 171452212
// Seneca email: vnhan1@myseneca.ca
// Date of completion: Apr 8, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <string>
#include "Station.h"


namespace sdds {
   struct Item {
      std::string m_itemName{};
      size_t m_serialNumber{ 0 };
      bool m_isFilled{ false };

      Item(const std::string& src) : m_itemName(src) {};
   };

   class CustomerOrder {
      std::string m_name{};
      std::string m_product{};
      size_t m_cntItem{};
      Item** m_lstItem{};
      static size_t m_widthField;
   public:
      CustomerOrder() {};
      CustomerOrder(const CustomerOrder& src);
      CustomerOrder& operator=(const CustomerOrder& src) = delete;
      CustomerOrder(CustomerOrder&& src) noexcept;
      CustomerOrder(const std::string& str);
      CustomerOrder& operator=(CustomerOrder&& src) noexcept;
      bool isOrderFilled() const;
      bool isItemFilled(const std::string& itemName) const;
      void fillItem(Station& station, std::ostream& os) const;
      void display(std::ostream& os) const;
      ~CustomerOrder();
      
   };
}


#endif // !SDDS_CUSTOMERORDER_H
