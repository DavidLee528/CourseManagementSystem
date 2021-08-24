#ifndef _TEACHER_H
#define _TEACHER_H

using std::string; 

class CTeacher {

private: 
    string username; 
    string password; 
    string name; 
    string major; 

public: 
    CTeacher(); 
    CTeacher(const string &_username); 
    CTeacher(const CTeacher &rhs); 
    ~CTeacher(); 

    CTeacher& operator=(const CTeacher &rhs); 

public: 
    
    string & GetTeacherUsername() const; 
    string & GetTeacherName() const; 
    string & GetTeacherMajor() const; 

    void SetTeacherUsername(const string &rhs); 
    void SetTeacherPassword(const string &rhs); 
    void SetTeacherName(const string &rhs); 
    void SetTeacherMajor(const string &rhs); 

    



}; 


#endif