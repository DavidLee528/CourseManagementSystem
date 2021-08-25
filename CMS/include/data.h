#ifndef _DATA_H
#define _DATA_H

#include <vector>

#include "../include/student.h"
#include "../include/teacher.h"
#include "../include/course.h"

using std::string; 
using std::vector; 

class CData {

public: 

    CData(); 
    ~CData(); 

    static bool CheckPasswordValidity(const std::pair<std::string, std::string> &input); 
    static bool GetUserAuthorization(const std::pair<std::string, std::string> &user, int &authCode); 


    // 通用接口
    static bool SetPassword(const string &username, const string &newPassword);   
    static bool FindTeacherByUsername(const string &username, CTeacher &teacher);   
    static bool FindStudentByUsername(const string &username, CStudent &student);   

    // 给CAdmin类提供的接口 (部分可给CTeacher类提供)
    static bool AddTeacherData(const CTeacher &teacher); 
    static bool DelTeacherData(const string &username); 
    static bool ModTeacherData(const CTeacher &teacher); 
    static bool QueTeacherData(vector<CTeacher> &teacherList, const string &username = "$default$"); 

    static bool AddStudentData(const CStudent &student); 
    static bool DelStudentData(const string &username); 
    static bool ModStudentData(const CStudent &student); 
    static bool QueStudentData(); 

    static bool AddCourseData(const CCourse &course); 
    static bool DelCourseData(const string &courseNumber); 
    static bool ModCourseData(const CStudent &course); 
    static bool QueCourseData(); 

    // 给CStudent类使用的接口
    static bool SelectCourse(const vector<string> &courseList, const string &username); 
    static bool CancelCourse(const vector<string> &courseList, const string &username); 
    static bool QueCourseResult(const string &username); 

private: 
    int authCode; 
    

}; 

#endif  