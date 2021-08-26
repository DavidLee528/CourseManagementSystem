#include <iostream>
#include <string>
#include <vector>

#include "../include/CMS.h"
#include "../include/data.h"
#include "../include/teacher.h"
#include "../include/student.h"
#include "../include/interface.h"

using std::cin; 
using std::cout; 
using std::endl; 
using std::string; 
using std::istream; 
using std::ostream; 
using std::vector; 

CTeacher::CTeacher() {

}

CTeacher::CTeacher(const string &_username): username(_username) {

    cout << "hello teacher. " << endl; 

}

CTeacher::CTeacher(const CTeacher &rhs) {
    *this = rhs; 
}

CTeacher::~CTeacher() {

}

/**
 * @description: 重载运算符=
 * @param {*} 
 * @return {*}
 */
CTeacher& CTeacher::operator=(const CTeacher &rhs) {
    if (this == &rhs) return *this; 
    username = rhs.username; 
    name = rhs.name; 
    major = rhs.major; 
    return *this; 
}

ostream& operator<<(ostream &os, const CTeacher &t) {
    os << GREEN << " [*] " << NONE; 
    os << "教工号:" << t.username;
    os << "  姓名:" << t.name; 
    os << "  专业:" << t.major; 
    os << endl; 
    return os; 
}

istream& operator>>(istream &is, CTeacher &t) {
    string str;
    cout << "教工号："; is >> str; t.SetTeacherUsername(str); 
    cout << "密  码："; is >> str; t.SetTeacherPassword(str); 
    cout << "姓  名："; is >> str; t.SetTeacherName(str); 
    cout << "专  业："; is >> str; t.SetTeacherMajor(str); 
    return is; 
}   

const string & CTeacher::GetTeacherUsername() const {
    return username; 
}

const string & CTeacher::GetTeacherName() const {
    return name; 
}

const string & CTeacher::GetTeacherMajor() const {
    return major; 
}

void CTeacher::SetTeacherUsername(const string &rhs) {
    username = rhs; 
}

void CTeacher::SetTeacherPassword(const string &rhs) {
    password = rhs; 
}

void CTeacher::SetTeacherName(const string &rhs) {
    name = rhs; 
}

void CTeacher::SetTeacherMajor(const string &rhs) {
    major = rhs; 
}


void CTeacher::ShowOptionsLv1(const CTeacher &teacher) {
    #ifndef DEBUG 
    system("clear"); 
    #endif
    string greeting = "你好, " + teacher.GetTeacherName() + "."; 
    CInterface::CMSPrompt(greeting); 
    cout << endl << endl; 
    cout << " [1] 查看个人信息" << endl; 
    cout << " [2] 修改个人密码" << endl; 
    cout << " [3] 查看课程列表" << endl; 
    cout << " [4] 查看学生列表" << endl; 
    cout << " [0] 退出系统" << endl << endl; 
}

void CTeacher::QueInfo(const CTeacher &teacher) {
    CInterface::CMSPrompt("查询个人信息"); 
    vector<CTeacher> self; 
    CData::QueTeacherData(self, teacher.GetTeacherUsername()); 
    cout << "教工号：" << self[0].GetTeacherUsername() << endl; 
    cout << "姓  名：" << self[0].GetTeacherName() << endl; 
    cout << "专  业：" << self[0].GetTeacherMajor() << endl; 
    CInterface::CMSPrompt("输入回车键以继续..."); 
    CInterface::Flush(); 
    getchar(); 
}

void CTeacher::ModPassword(const CTeacher &teacher) {
    CInterface::CMSPrompt("修改个人密码，请输入新密码："); 
    string newPassword; 
    cin >> newPassword; 
    if (!CData::SetPassword(teacher.GetTeacherUsername(), newPassword))
        CInterface::CMSErrorReport("Fail to update password."); 
    CInterface::CMSPrompt("密码修改成功，输入回车键以继续..."); 
    CInterface::Flush(); 
    getchar(); 
}

void CTeacher::QueCourseList() {
    CInterface::CMSPrompt("查询课程列表"); 
    vector<CCourse> courseList; 
    CData::QueCourseData(courseList); 
    CInterface::CMSPrompt("输入回车键以继续..."); 
    CInterface::Flush(); 
    getchar(); 
}

void CTeacher::QueStudentList() {
    CInterface::CMSPrompt("查询学生列表"); 
    vector<CStudent> studentList; 
    CData::QueStudentData(); 
    CInterface::CMSPrompt("输入回车键以继续..."); 
    CInterface::Flush(); 
    getchar(); 
}