#ifndef _INTERFACE_H
#define _INTERFACE_H

#include "admin.h"
#include "student.h"
#include "teacher.h"

class CInterface {

public: 

    static bool DisplayErrorMessage(const std::string &msg); 

    static bool Login(); 
    static bool UserInfoInput(std::string &username, std::string &password); 
    static bool InitScreen(); 

    static void aMain(CAdmin &admin); 
    static void sMain(CStudent &student); 
    static void tMain(CTeacher &teacher); 

    static void GetOption(const string &hint, char option); 


    
}; 

#endif