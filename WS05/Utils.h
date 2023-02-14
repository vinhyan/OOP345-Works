#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H


#include <string>

namespace sdds {
   void extractToken(std::string& str, std::string& token, char delim);
   void extractToken(std::string& str, size_t& token, char delim);
   void extractToken(std::string& str, double& token, char delim);
   void trim(std::string& str);





}
#endif // !SDDS_UTILS_H
