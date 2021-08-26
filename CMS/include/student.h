#ifndef _STUDENT_H
#define _STUDENT_H

using std::string; 
using std::istream; 
using std::ostream; 

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

    CStudent& operator=(const CStudent &rhs); 
    friend ostream& operator<<(ostream &os, const CStudent &t); 
    friend istream& operator>>(istream &is, CStudent &t); 

public: 

    const string & GetStudentUsername() const; 
    const string & GetStudentName() const ; 
    const string & GetStudentMajor() const ; 
    const string & GetStudentCourse() const ; 

    void SetStudentUsername(const string &rhs); 
    void SetStudentPassword(const string &rhs); 
    void SetStudentName(const string &rhs); 
    void SetStudentMajor(const string &rhs); 
    void SetStudentCourse(const string &rhs); 

    static void ShowOptionsLv1(const CStudent &student); 
    
    static bool Check_Change(const string &option, CStudent &student); 
    static bool Selection(CStudent &student); 
    static bool CheckCourse(CStudent &student);
    static bool Deselection(CStudent &student);

    static bool CheckSelfInfo(CStudent &student); 

    // 更换密码
    bool ChangePass(const string &newPassword); 

    // 选课与退选课
    bool SelectCourse(const string &courseNumber); 
    bool CancelCourse(const string &courseNumber); 

    // 显示个人信息与显示选课结果
    bool ShowMyInfo(); 
    bool ShowMyCourseList(); 

    friend class CData; 
}; 

#endif
