#ifndef _STUDENT_H
#define _STUDENT_H

using std::string; 

class CStudent {

private: 
    string username; 
    string password; 
    string name; 
    string major; 

public: 
    CStudent(); 
    CStudent(const string &_username); 
    CStudent(const CStudent &rhs); 
    ~CStudent(); 

public: 

    string & GetStudentUsername() ; 
    string & GetStudentName(); 
    string & GetStudentMajor(); 

    void SetStudentUsername(const string &rhs); 
    void SetStudentPassword(const string &rhs); 
    void SetStudentName(const string &rhs); 
    void SetStudentMajor(const string &rhs); 
    

}; 

#endif