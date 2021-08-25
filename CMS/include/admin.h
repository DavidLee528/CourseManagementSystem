/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 
 * @ E-mail: 13121515269@163.com
 */
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

    // 分支
    static void ShowOptionsLv1(); 
    static void ShowOptionsLv2_1(); 
    static void ShowOptionsLv2_2(); 
    static void ShowOptionsLv2_3(); 

    static bool ManageTeacher();     // 1
    static bool ManageStudent(const string &option);     // 2
    static bool ManageCourse(const string &option);      // 3
    
    static void AddTeacher();                           // 1-1
    static void DelTeacher();                           // 1-2
    static void ModTeacher();                           // 1-3
    static void QueTeacher();                           // 1-4

    static void AddStudent();                           // 2-1
    static void DelStudent();                           // 2-2
    static void ModStudent();                           // 2-3
    static void QueStudent();                           // 2-4

    static void AddCourse();                            // 3-1
    static void DelCourse();                            // 3-2
    static void ModCourse();                            // 3-3
    static void QueCourse();                            // 3-4

    

    

}; 

#endif