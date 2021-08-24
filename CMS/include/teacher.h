#ifndef _TEACHER_H
#define _TEACHER_H

using std::string; 

class CTeacher {

private: 
    string username; 
    string name; 

public: 
    CTeacher(const string &_username); 
    CTeacher(const CTeacher &rhs); 
    ~CTeacher(); 
    
    string & GetTeacherUsername(); 
    string & GetTeacherName(); 

}; 


#endif