// Name: Vinh Nhan
// Seneca Student ID: 171452212
// Seneca email: vnhan1@myseneca.ca
// Date of completion: Apr 8, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_LINE_MANAGER_H
#define SDDS_LINE_MANAGER_H

#include <string>
#include <vector>
#include "Workstation.h"

namespace sdds {
   class LineManager {
      std::vector<Workstation*> m_activeLine{};
      size_t m_cntCustomerOrder{};
      Workstation* m_firstStation{};
   public:
      LineManager();
      LineManager(const std::string& file, const std::vector<Workstation*>& stations);bool cont = true;
      void reorderStations();
      void display(std::ostream& os) const;
      bool run(std::ostream& os);



   };

}

























#endif // !SDDS_LINE_MANAGER_H


