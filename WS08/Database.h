#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <iostream>
#include <memory>
#include <string>



namespace sdds {
   const int ARR_SIZE = 20;
   enum class Err_Status {
      Err_Success,
      Err_NotFound,
      Err_OutOfMemory,
   };

   class Database {
      static std::shared_ptr<Database> m_addr; //reflection
      size_t m_num_entry{};
      std::string m_keys[ARR_SIZE];
      std::string m_values[ARR_SIZE];
      std::string m_filename{};
   //protected: or private?
      Database() {};
      Database(const std::string& filename);
   public:
      static std::shared_ptr<Database> getInstance(const std::string& filename);
      Err_Status GetValue(const std::string& key, std::string& value) const;
      Err_Status SetValue(const std::string& key, std::string& value);
      ~Database();

   };


}








#endif // !SDDS_DATABASE_H


