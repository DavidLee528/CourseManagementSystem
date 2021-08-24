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
    

}; 

#endif