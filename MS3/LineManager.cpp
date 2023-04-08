// Name: Vinh Nhan
// Seneca Student ID: 171452212
// Seneca email: vnhan1@myseneca.ca
// Date of completion: Apr 8, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <fstream>
#include <algorithm>
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

      if (inf) {
         while (getline(inf, str)) {
            bool more = true;
            size_t next_pos{};
            Workstation* tmp_ws{};
            size_t lastStnCnt{};
            //get the name of current station and next station from file
            string curr_stn_token = util.extractToken(str, next_pos, more);
            string next_stn_token = util.extractToken(str, next_pos, more);

            //add next_stn_token to list of stations that ARE NOT first station
            if (!next_stn_token.empty()) {
               not_first_stns.push_back(next_stn_token);
            }
            else {
               lastStnCnt++;
            }

            if (lastStnCnt > 1) {
               throw "There are more than 1 last station";
            }
            
            //bool found = false;
            //for (auto it = stations.begin(); it != stations.end() && !found; it++) {
            //   if ((*it)->getItemName() == curr_stn_token) {
            //      m_activeLine.push_back(*it);  //push current station to m_active
            //      
            //      //if current station is not the last one, set its next station. Do nothing if it is
            //      if (!next_stn_token.empty()) { 
            //         for (auto jt = stations.begin(); jt != stations.end() && !found; jt++) {
            //            if ((*jt)->getItemName() == next_stn_token) {
            //               m_activeLine[stn_cnt]->setNextStation(*jt);
            //               found = true;
            //            }
            //         }                   
            //      }

            //      found = true;
            //      stn_cnt++;
            //   }
            //}
            for_each(stations.begin(), stations.end(), [&curr_stn_token, &tmp_ws](Workstation* ws) {
                  if (ws->getItemName() == curr_stn_token) {
                     tmp_ws = ws;
                  }
               });            

            if (!next_stn_token.empty()) {
               for_each(stations.begin(), stations.end(), [&next_stn_token, &tmp_ws](Workstation* ws) {
                     if (ws->getItemName() == next_stn_token) {
                        tmp_ws->setNextStation(ws);
                     }
                  });
            }
            else {
               tmp_ws->setNextStation(nullptr);
            }
            m_activeLine.push_back(tmp_ws);
         }
      
         //bool found{};
         //bool cont = true;

         //for (auto it = m_activeLine.begin(); it != m_activeLine.end() && cont; it++) {
         //   found = false;
         //   for (auto jt = not_first_stns.begin(); jt != not_first_stns.end() && !found; jt++) {
         //      found = ((*it)->getItemName() == *jt);
         //   }

         //   //STL
         //   /*string itemName = (*it)->getItemName();
         //   found = any_of(not_first_stns.begin(), not_first_stns.end(), [&itemName](const string& stn_name) {
         //      return itemName == stn_name;
         //      });*/

         //   if (!found) {
         //      m_firstStation = *it;
         //      cont = false;
         //   } 
         //}

         //**************** STL **************************
         Workstation* tmp_firstStn{};
         size_t firstStnCnt{};

         for_each(m_activeLine.begin(), m_activeLine.end(), [&not_first_stns, &tmp_firstStn, &firstStnCnt](Workstation* ws) {
            string itemName = (ws)->getItemName();
            bool found = any_of(not_first_stns.begin(), not_first_stns.end(), [&itemName](const string& stn_name) {
               return itemName == stn_name;
               });
            if (!found) {
               tmp_firstStn = ws;
               firstStnCnt++;
            }
            });
         if (firstStnCnt > 1) {
            throw "There are more than 1 first station";
         }
         m_firstStation = tmp_firstStn;
         //**************** END STL **************************
      }
      else {
         throw "File cannot be found!";
      }

      m_cntCustomerOrder = g_pending.size();

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

      os << "Line Manager Iteration: " << cnt++ << endl;

      if (g_pending.size() > 0) {
         *m_firstStation += (move(g_pending.front()));
         g_pending.pop_front();
      }

      //first call first loop, order has not been moved, therefore nothing gets filled
      for (auto it = m_activeLine.begin(); it != m_activeLine.end() ; it++) {
         (*it)->fill(os);
      }
      //move orders, so the next call can fill
      for (auto i = 0u; i < m_activeLine.size(); i++) {
         (m_activeLine[i]->attemptToMoveOrder());
      }
   
      (g_completed.size() + g_incomplete.size() == m_cntCustomerOrder ? status = true : status = false);


      return status;
   }

}