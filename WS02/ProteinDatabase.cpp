/*
Full name: Vinh Nhan
Student ID: 171452212
OOP345 - Workshop 2
Date: Jan 27, 2023
*/


//#include <iostream>
#include <fstream>
#include "ProteinDatabase.h"



using namespace std;
namespace sdds {
   ProteinDatabase::ProteinDatabase(std::string filename) {
      std::string tmp;
      unsigned int cnt{};

      ifstream infile(filename);

      if (infile.is_open()) {
         while (getline(infile, tmp)) {
            if (tmp[0] == '>') cnt++;
         }
      }
      
      infile.clear();
      infile.seekg(0); //read file from beginning

      delete[] m_proteinArr;
      m_proteinArr = nullptr;

      if (!infile.fail()) {
         m_proteinArr = new string[cnt];
         while (getline(infile, tmp)) {
            if (tmp[0] != '>') {
               m_proteinArr[m_num_protein - 1] += tmp;
            }
            else {
               m_num_protein++;
            }
         }
      }
   }
   size_t ProteinDatabase::size() {
      return m_num_protein;
   }
   std::string ProteinDatabase::operator[](size_t i) {
      string protein{};
      if (i >= 0 && i < m_num_protein) {
         protein = m_proteinArr[i];
      }
      return protein;
   }
   ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& PD) {
      if (this != &PD) {
         m_num_protein = PD.m_num_protein;
         delete[] m_proteinArr;
         m_proteinArr = nullptr;

         if (PD.m_proteinArr) {   // always check src
            m_proteinArr = new string[m_num_protein];
            for (unsigned int i = 0; i < m_num_protein; i++) {
               m_proteinArr[i] = PD.m_proteinArr[i];
            }
         }
         
      }
      return *this;
   }
   ProteinDatabase::ProteinDatabase(const ProteinDatabase& PD) {
      *this = PD;
   }
   ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& PD) noexcept {
      if (this != &PD) {
         //make sure house is empty before moving in furnitures
         delete[] m_proteinArr; 
         m_proteinArr = nullptr; 
         //move furnitures from other house
         m_num_protein = PD.m_num_protein;
         m_proteinArr = PD.m_proteinArr;
         //make other house empty (of furnitures)
         PD.m_num_protein = 0;
         PD.m_proteinArr = nullptr;
      }
      return *this;
   }
   ProteinDatabase::ProteinDatabase(ProteinDatabase&& PD) noexcept {
      *this = move(PD);
   }
   ProteinDatabase::~ProteinDatabase() {
      delete[] m_proteinArr;
   }
}