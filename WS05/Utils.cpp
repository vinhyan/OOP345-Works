#include "Utils.h"


using namespace std;

namespace sdds {
   void extractToken(std::string& str, std::string& token, char delim) {
      size_t pos = str.find(delim);
      if (pos == string::npos) {
         token = str;
         trim(token);
      }
      else {
         token = str.substr(0, pos);
         trim(token);
         str.erase(0, pos + 1);
      }
   }

   void extractToken(std::string& str, unsigned int& token, char delim) {
      size_t pos = str.find(delim);
      if (pos == string::npos) {
         token = stoi(str);
      }
      else {
         token = stoi(str.substr(0, pos));
         str.erase(0, pos + 1);
      }
   }

   void extractToken(std::string& str, double& token, char delim) {
      size_t pos = str.find(delim);
      if (pos == string::npos) {
         token = stod(str);
      }
      else {
         token = stod(str.substr(0, pos));
         str.erase(0, pos + 1);
      }
   }

   void trim(std::string& str) {
      size_t firstPos = str.find_first_not_of(" \f\n\r\t\v");
      str.erase(0, firstPos);
      size_t lastPos = str.find_last_not_of(" \f\n\r\t\v");
      str.erase(lastPos + 1);
   }





}