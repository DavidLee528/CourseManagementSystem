#ifndef _INTERFACE_H
#define _INTERFACE_H

class CInterface {

public: 
    static void rMain(); 

    static bool Login(); 
    static bool UserInfoInput(std::string &username, std::string &password); 
    static bool GetUserAuthorization(const std::pair<std::string, std::string> &user, int &authCode); 
    static bool InitScreen(); 

    static bool DisplayErrorMessage(const std::string &msg); 
}; 

#endif