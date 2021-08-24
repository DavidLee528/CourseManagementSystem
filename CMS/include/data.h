#ifndef _DATA_H
#define _DATA_H

#include "teacher.h"

using std::string; 

class CData {

public: 

    CData(); 
    ~CData(); 

    static bool CheckPasswordValidity(const std::pair<std::string, std::string> &input); 
    static bool GetUserAuthorization(const std::pair<std::string, std::string> &user, int &authCode); 

    static bool SetPassword(const string &username, const string &newPassword);     


    
    // 提供给CAdmin类使用的接口
    static bool AddTeacherData(const CTeacher &teacher); 
    static bool DelTeacherData(const string &username); 
    static bool ModTeacherData(const CTeacher &teacher); 
    static bool QueTeacherData(); 

private: 
    int authCode; 
    

}; 

#endif