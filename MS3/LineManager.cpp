// Name: Vinh Nhan
// Seneca Student ID: 171452212
// Seneca email: vnhan1@myseneca.ca
// Date of completion: Apr 8, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <fstream>
#include "LineManager.h"
#include "Utilities.h"



using namespace std;
namespace sdds {

   LineManager::LineManager() {}

   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
      ifstream inf(file);
      string str{};
      
      Utilities util{};
      util.setDelimiter('|');

      vector<string> not_first_stns{};
      size_t stn_cnt{};

      if (inf) {
         while (getline(inf, str)) {
            bool more = true;
            size_t next_pos{};
            bool found = false;

            //get the name of current station and next station from file
            string curr_stn_token = util.extractToken(str, next_pos, more);
            string next_stn_token = util.extractToken(str, next_pos, more);

            //add next_stn_token to list of stations that ARE NOT first station
            if (!next_stn_token.empty()) not_first_stns.push_back(next_stn_token);

            for (auto it = stations.begin(); it != stations.end() && !found; it++) {
               if ((*it)->getItemName() == curr_stn_token) {
                  m_activeLine.push_back(*it);  //push current station to m_active
                  
                  //if current station is not the last one, set its next station. Do nothing if it is
                  if (!next_stn_token.empty()) { 
                     for (auto jt = stations.begin(); jt != stations.end() && !found; jt++) {
                        if ((*jt)->getItemName() == next_stn_token) {
                           m_activeLine[stn_cnt]->setNextStation(*jt);
                           found = true;
                        }
                     }                   
                  }
                  found = true;
                  stn_cnt++;
               }
            }
            //identify first and last station from the file to figure out the order of the station

            //loop thru station vector and sort according to the order

            //THROW EXCEPTION
               //what if there are 2 last stations (2 that are not next to any station)
         }

         bool found{};
         bool cont = true;

         for (auto it = m_activeLine.begin(); it != m_activeLine.end() && cont; it++) {
            found = false;
            for (auto jt = not_first_stns.begin(); jt != not_first_stns.end() && !found; jt++) {
               found = ((*it)->getItemName() == *jt);
            }
            if (!found) {
               m_firstStation = *it;
               cont = false;
            } 
         }
      }
   }

   void LineManager::reorderStations() {
      size_t cnt{};
      bool cont = true;
      vector<Workstation*> reorderedStns{};
      reorderedStns.push_back(m_firstStation);
      //reorderedStns.push_back(m_firstStation->getNextStation());

      for (auto it = m_activeLine.begin(); it != m_activeLine.end() && cont; it++) {
         if (reorderedStns[cnt]->getNextStation()->getItemName() == (*it)->getItemName()) {
            reorderedStns.push_back(*it);
            cnt++;
            cont = false;
         }
         
      }

   }

   void LineManager::display(std::ostream& os) const {
      for (auto it = m_activeLine.begin(); it != m_activeLine.end(); it++) {
         (*it)->display(os);
      }
      //os << "first station: ";
      //m_firstStation->display(os);
      //os << std::endl;
   }

}