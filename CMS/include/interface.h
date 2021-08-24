#ifndef _INTERFACE_H
#define _INTERFACE_H

#include "admin.h"
#include "student.h"
#include "teacher.h"

using std::string; 

class CInterface {

public: 

    static bool CMSErrorReport(const string &msg); 

    static bool Login(); 
    static bool UserInfoInput(string &username, string &password); 
    static bool InitScreen(); 

    static void aMain(CAdmin &admin); 
    static void sMain(CStudent &student); 
    static void tMain(CTeacher &teacher); 

    static void GetOption(const string &prompt, string &option); 
    static void CMSPrompt(const string &prompt); 
    #ifdef _WIN32
    static string & WindowsGetPass(const string prompt, string &password); 
    #endif

    static void Menu(); 
    static void Flush(); 
    static string& GetDate(); 


    
}; 

#endif