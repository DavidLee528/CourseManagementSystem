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
    CStudent(const string &_username); 
    CStudent(const CStudent &rhs); 
    ~CStudent(); 

    string & GetStudentUsername(); 
    string & GetStudentName(); 
    string & GetStudentMajor(); 
    

}; 

#endif