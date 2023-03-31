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

      m_cntCustomerOrder = g_pending.size();
      //THROW EXCEPTION
         //what if there are 2 last stations (2 that are not next to any station)
   }

   void LineManager::reorderStations() {
      vector<Workstation*> reorderedStns;

      Workstation* ws = m_firstStation;

      while (ws != nullptr) {
         reorderedStns.push_back(ws);
         ws = ws->getNextStation();
      }

      m_activeLine = reorderedStns;
   }

   void LineManager::display(std::ostream& os) const {
      for (auto it = m_activeLine.begin(); it != m_activeLine.end(); it++) {
         (*it)->display(os);
      }
   }

   bool LineManager::run(std::ostream& os) {
      static size_t cnt = 1;
      bool status{};
      bool isMoved{true};
      CustomerOrder* order = &(g_pending.front());
      os << "Line Manager Iteration: " << cnt++ << endl;

      *m_firstStation += (move(*order));

      g_pending.pop_front();

      //first loop, order has not been moved, therefore nothing gets filled
      for (auto it = m_activeLine.begin(); it != m_activeLine.end() ; it++) {
         (*it)->fill(os);
      }
      //move order, so the next loop can fill
      auto i = 0u;
      for (; i < m_activeLine.size(); i++) {
         isMoved = m_activeLine[i]->attemptToMoveOrder();
      }

 

   /*   vector<size_t> filled_idx{};
      for (auto i = 0u; i < m_activeLine.size(); i++) {
         m_activeLine[i]->fill(os);
      }*/




      //if (cnt == 3) m_activeLine[4]->attemptToMoveOrder();
      //it++;
      //for (; it != m_activeLine.end() && isMoved; it++) {
      //   isMoved = (*it)->attemptToMoveOrder();
      //}
      /*if (!isMoved) {
         
      }*/


      g_pending.size() > 0 ? status = false : status = true;
  


      return status;
   }

}