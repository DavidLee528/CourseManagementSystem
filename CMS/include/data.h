#ifndef _DATA_H
#define _DATA_H

class CData {

public: 

    CData(); 
    ~CData(); 



    static bool CheckPasswordValidity(const std::pair<std::string, std::string> &input); 
    static bool GetUserAuthorization(const std::pair<std::string, std::string> &user, int &authCode); 


}; 

#endif