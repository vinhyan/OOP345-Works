#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <memory>
#include <string>



namespace sdds {
   const int ARR_SIZE = 20;
   enum class Err_Status {
      Err_Success,
      Err_NotFound,
      Err_OutOfMemory,
   };
   //singleton = only one instance of the class the whole program
   //class Database {
   //   static std::shared_ptr<Database> m_addr; //reflection
   //   size_t m_num_entry{};
   //   std::string m_keys[ARR_SIZE];
   //   std::string m_values[ARR_SIZE];
   //   std::string m_filename{};
   ////protected: or private?
   //   Database() {};
   //   Database(const std::string& filename);
   //public:
   //   static std::shared_ptr<Database> getInstance(const std::string& filename);
   //   Err_Status GetValue(const std::string& key, std::string& value) const;
   //   Err_Status SetValue(const std::string& key, std::string& value);
   //   ~Database();

   //};
   template<class T>
   class Database {
      inline static std::shared_ptr<Database> m_addr{}; //reflection
      size_t m_num_entry{};
      std::string m_keys[ARR_SIZE];
      T m_values[ARR_SIZE];
      std::string m_filename{};
      //protected: or private?
      Database() {};
      Database(const std::string& filename) {
            //hex style for the address
         std::cout << "[" << this << "]" << " Database(const std::string&)" << std::endl;
         m_filename = filename;

         std::ifstream file(filename);

         while (m_num_entry < ARR_SIZE && (file >> m_keys[m_num_entry] && file >> m_values[m_num_entry])) {
            size_t pos = m_keys[m_num_entry].find_first_of("_");
            if (pos != std::string::npos) 
               m_keys[m_num_entry].replace(pos, 1, " ");
            encryptDecrypt(m_values[m_num_entry]);
            m_num_entry++;
         }
      };

      void encryptDecrypt(T& value) {};

   public:
      static std::shared_ptr<Database> getInstance(const std::string& filename) {
         if (!m_addr) {
            std::shared_ptr<Database> inst(new Database<T>(filename));
            m_addr = inst; //shared pointer allows copy
         }

         return m_addr;

      }
      Err_Status GetValue(const std::string& key, T& value) const {
         bool found{};
         Err_Status status;
         auto i = 0u;
         for (; i < m_num_entry && !found; i++) {
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


      };
      Err_Status SetValue(const std::string& key, const T& value) {
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
      };



      ~Database() {
         std::cout << "[" << this << "]" << " ~Database()" << std::endl;
         std::string bkpFilename = m_filename + ".bkp.txt";
         std::ofstream file(bkpFilename);

         if (file) {
            for (auto i = 0u; i < m_num_entry; i++) {
               encryptDecrypt(m_values[i]);
               file << std::setw(25) << std::left << m_keys[i]
                  << "-> " << m_values[i] << std::endl;
            }
         }
         else {
            throw "Unable to open file!";
         }

      };

   };

   template<>
   void Database<std::string>::encryptDecrypt(std::string& value) {
      const char secret[]{ "secret encryption key" };
      for (char& C : value) {
         for (const char& K : secret) {
            C = C ^ K;
         }

      }
   }

   template<>
   void Database<long long>::encryptDecrypt(long long& value) {
      const char secret[]{ "secret encryption key" };

     // value is a long long
      char* c = reinterpret_cast<char*>(&value);

      for (auto i = 0u; i < sizeof(c); i++ )
         for (const char& K : secret) {
            c[i] = c[i] ^ K;
         }
   }



}








#endif // !SDDS_DATABASE_H


