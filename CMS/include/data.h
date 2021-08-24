#ifndef _DATA_H
#define _DATA_H

using std::string; 

class CData {

public: 

    CData(); 
    ~CData(); 

    static bool CheckPasswordValidity(const std::pair<std::string, std::string> &input); 
    static bool GetUserAuthorization(const std::pair<std::string, std::string> &user, int &authCode); 

    static bool UpdatePassword(const string &username);     

private: 
    int authCode; 
    

}; 

#endif