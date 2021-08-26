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
}

void CTeacher::ModPassword(const CTeacher &teacher) {
    CInterface::CMSPrompt("修改个人密码"); 
    string newPassword; 
    cin >> newPassword; 
    if (!CData::SetPassword(teacher.GetTeacherUsername(), newPassword))
        CInterface::CMSErrorReport("Fail to update password."); 
    CInterface::CMSPrompt("密码修改成功，输入任意键以继续..."); 
    CInterface::Flush(); 
    getchar(); 
}

void CTeacher::QueCourseList() {
    CInterface::CMSPrompt("查询课程列表, 请输入课程编号(输入#以查询全部课程)"); 
    string str; cin >> str; 
    vector<CCourse> courseList; 
    if (str == "#") CData::QueCourseData(courseList); 
    else CData::QueCourseData(courseList, str); 
    // TODO:打印课程列表
    // 
    CInterface::CMSPrompt("输入任意键以继续..."); 
    CInterface::Flush(); 
    getchar(); 
}

void CTeacher::QueStudentList() {
    CInterface::CMSPrompt("查询学生列表, 请输入学号(输入#以查询全部学生)"); 
    string str; cin >> str; 
    vector<CStudent> studentList; 
    if (str == "#") CData::QueStudentData(studentList); 
    else CData::QueStudentData(studentList, str); 
    // TODO:打印学生列表
    // 
    CInterface::CMSPrompt("输入任意键以继续..."); 
    CInterface::Flush(); 
    getchar(); 
}