#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H

#include <string>

namespace sdds {
   class ProteinDatabase {
      std::string* m_proteinArr{};
      unsigned int m_num_protein{};
   public:
      ProteinDatabase() {};
      ProteinDatabase(std::string filename);
      size_t size();
      std::string operator[](size_t);
      ProteinDatabase& operator=(const ProteinDatabase& PD);
      ProteinDatabase(const ProteinDatabase& PD);
      ProteinDatabase& operator=(ProteinDatabase&& PD) noexcept;
      ProteinDatabase(ProteinDatabase&& PD) noexcept;
      ~ProteinDatabase();
   };
}




#endif // !SDDS_PROTEINDATABASE_H

