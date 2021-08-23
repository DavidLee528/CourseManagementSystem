#ifndef _STUDENT_H
#define _STUDENT_H

class CStudent {

private: 
    std::string username; 
    std::string password; 
    std::string name; 
    std::string major; 

public: 
    std::string & GetStudentUsername(); 
    std::string & GetStudentName(); 
    std::string & GetStudentMajor(); 
    

}; 

#endif