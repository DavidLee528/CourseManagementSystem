#ifndef _STUDENT_H
#define _STUDENT_H

using std::string; 

class CStudent {

protected: 
    string username; 
    string password; 
    string name; 
    string major; 
    string course; 
public: 
    CStudent(); 
    CStudent(const string &_username); 
    CStudent(const CStudent &rhs); 
    ~CStudent(); 

public: 

    const string & GetStudentUsername() const ; 
    const string & GetStudentName() const ; 
    const string & GetStudentMajor() const ; 

    void SetStudentUsername(const string &rhs); 
    void SetStudentPassword(const string &rhs); 
    void SetStudentName(const string &rhs); 
    void SetStudentMajor(const string &rhs); 

    // 选课与退选课
    bool SelectCourse(CStudent &student); 
    bool CancelCourse(CStudent &student); 

    friend class CData; 

}; 

#endif