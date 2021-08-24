#ifndef _ADMIN_H
#define _ADMIN_H

using std::string; 

class CAdmin {

private: 
    string username; 
    string password; 
    string name; 

public: 
    CAdmin(const string &_username); 
    CAdmin(const CAdmin &rhs); 
    ~CAdmin(); 

    static void GetOption(const string &hint, char option); 
    static void ShowOptionsLv1(); 
    static void ShowOptionsLv2_1(); 
    static void ShowOptionsLv2_2(); 
    static void ShowOptionsLv2_3(); 
    

}; 

#endif