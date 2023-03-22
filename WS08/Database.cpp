#include <fstream>
#include "Database.h"


using namespace std;
namespace sdds {
   std::shared_ptr<Database> Database::m_addr{};

   Database::Database(const std::string& filename) {
      cout << "[" << this << "]" << " Database(const std::string&)" << endl;
      m_filename = filename;

      ifstream file(filename);
      string tmp{};
      string token{};
      size_t pos{};
      size_t i{};
      while (getline(file, tmp) && i < ARR_SIZE) {
         //get keys
         pos = tmp.find_first_of(" ");
         token = tmp.substr(0, pos);
         pos = token.find_first_of("_");
         token.replace(pos, 1, " ");
         m_keys[i] = token;

         //get values
         pos = tmp.find_last_of(" ");
         token = tmp.substr(pos + 1);

         m_values[i] = token;

         i++;
      }
      m_num_entry = i;
   }

   std::shared_ptr<Database> Database::getInstance(const std::string& filename) {
      shared_ptr<Database> inst(new Database(filename));

      if (!m_addr) {
         m_addr = inst; //shared pointer allows copy
      }

      return m_addr;
   }

   Err_Status Database::GetValue(const std::string& key, std::string& value) const {
      bool found{};
      Err_Status status;
      auto i = 0u;
      for (; i < ARR_SIZE && !found; i++) {
         found = m_keys[i] == key;
      }

      if (found && i--) {
         value = m_values[i];
         status = Err_Status::Err_Success;
      }
      else {
         status = Err_Status::Err_NotFound;
      }
      return status;
   }

   Err_Status Database::SetValue(const std::string& key, std::string& value) {
      Err_Status status;

      if (m_num_entry < ARR_SIZE) {
         m_keys[m_num_entry - 1] = key;
         m_values[m_num_entry - 1] = value;
         status = Err_Status::Err_Success;
      }
      else {
         status = Err_Status::Err_OutOfMemory;
      }

      return status;
   }

   Database::~Database() {
      cout << "[" << this << "]" << " ~Database()" << endl;
      //string bkpFilename = m_filename + ".bkp."
      //ofstream file("")
   }

}
