#ifndef _TEACHER_H
#define _TEACHER_H

using std::string; 
using std::istream; 
using std::ostream; 

class CTeacher {

protected: 
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
    friend ostream& operator<<(ostream &os, const CTeacher &t); 
    friend istream& operator>>(istream &is, CTeacher &t); 

public: 
    
    // 接口
    const string & GetTeacherUsername() const; 
    const string & GetTeacherName() const; 
    const string & GetTeacherMajor() const; 
    void SetTeacherUsername(const string &rhs); 
    void SetTeacherPassword(const string &rhs); 
    void SetTeacherName(const string &rhs); 
    void SetTeacherMajor(const string &rhs); 

    // 分支
    static void ShowOptionsLv1(const CTeacher &teacher); 

    // 功能
    static void QueInfo(const CTeacher &teacher); 
    static void ModPassword(const CTeacher &teacher); 
    static void QueCourseList(); 
    static void QueStudentList(); 

    
    friend class CData; 


}; 


#endif