#include <iostream>
#include <string>
#include <sstream>

#include "../include/student.h"
#include "../include/CMS.h"
#include "../include/data.h"
#include "../include/interface.h"
#include "../include/course.h"

using std::cin;
using std::cout; 
using std::endl; 
using std::string; 
using std::istream; 
using std::ostream; 
using std::stringstream; 

CStudent::CStudent() {
    
}

CStudent::CStudent(const string &_username): username(_username) { 
    CStudent s; 
    CData::FindStudentByUsername(username, s); 
    name = s.name; 
    major = s.major; 
    course = s.course; 
}

CStudent::CStudent(const CStudent &rhs) {
    *this = rhs; 
}

CStudent::~CStudent() {
    // 更新文件信息
    CData::ModStudentData(*this, username); 
}


/**
 * @description: 重载运算符=
 * @param {*} 
 * @return {*}
 */
CStudent& CStudent::operator=(const CStudent &rhs) {
    if (this == &rhs) return *this; 
    username = rhs.username; 
    name = rhs.name; 
    major = rhs.major; 
    return *this; 
}

ostream& operator<<(ostream &os, const CStudent &t) {
    os << GREEN << " [*] " << NONE; 
    os << "学  号:" << t.username << " "; 
    os << "姓  名:" << t.name << " "; 
    os << "专  业:" << t.major << " "; 
    os << endl; 
    return os; 
}

istream& operator>>(istream &is, CStudent &t) {
    string str;
    cout << "学  号："; is >> str; t.SetStudentUsername(str); 
    cout << "密  码："; is >> str; t.SetStudentPassword(str); 
    cout << "姓  名："; is >> str; t.SetStudentName(str); 
    cout << "专  业："; is >> str; t.SetStudentMajor(str); 
    return is; 
}   

const string & CStudent::GetStudentUsername() const {
    return username; 
}

const string & CStudent::GetStudentName() const {
    return name; 
}

const string & CStudent::GetStudentMajor() const {
    return major; 
}

const string & CStudent::GetStudentCourse() const {
    return course; 
}

void CStudent::SetStudentUsername(const string &rhs) {
    username = rhs; 
}

void CStudent::SetStudentPassword(const string &rhs) {
    password = rhs; 
}

void CStudent::SetStudentName(const string &rhs) {
    name = rhs; 
}

void CStudent::SetStudentMajor(const string &rhs) {
    major = rhs; 
}

void CStudent::SetStudentCourse(const string &rhs) {
    course = rhs;
}

void CStudent::ShowOptionsLv1(const CStudent &student) {
    #ifndef DEBUG
    SYSTEM_CLEAR_SCREEN
    #endif
    string greeting = "你好，" + student.GetStudentName(); 
    CInterface::CMSPrompt(greeting); 
    cout << endl << endl;
    cout << " [1] 查看个人信息" << endl;
    cout << " [2] 修改个人密码" << endl;
    cout << " [3] 选课       "     << endl;
    cout << " [4] 查看选课结果"     << endl;
    cout << " [5] 退选       "     << endl;
    cout << " [0] 退出系统    "     << endl << endl;
}

bool CStudent::CheckSelfInfo(CStudent &student) {
    CData::FindStudentByUsername(student.GetStudentUsername(), student); 
    cout << student.GetStudentUsername() << " "
            << student.GetStudentName() << " "
            << student.GetStudentMajor() << endl;
    cout << endl; 
    CInterface::Flush(); 
    getchar(); 
    return true; 
}

bool CStudent::ChangePass(const string &newPassword) {
    CData::SetPassword(username, newPassword);
    CInterface::CMSPrompt("密码更改成功。"); 
    CInterface::Flush(); 
    getchar(); 
    return true; 
}


bool CStudent::ShowMyInfo() {
    cout << *this << endl; 
    CInterface::Flush(); 
    getchar(); 
    return true; 
}



/**
 * @description: 名  称: 选课
 *               调用者: CInterface类sMain函数
 *               功  能: 在CStudent类对象的私有数据成员course
 *                       后追加一个6位课程编码
 *               备  注: 000000,600001,600003,600008
 *                      初始字符串为000000
 *                      每次追加,xxxxxx
 * @param {CStudent} &student 需要拼接前置英文逗号
 * @return {*} 为真则成功
 */
bool CStudent::SelectCourse(const string &courseNumber) {

    // 找到重复课程
    if (course.find(courseNumber) != string::npos) 
        return CInterface::CMSErrorReport("Course Exist."); 

    // 尾后拼接新课程编码
    course = course + courseNumber; 

    return true; 
}

/**
 * @description: 退选课
 *               调用者: CInterface类sMain函数
 *               功  能: 在CStudent类对象的私有数据成员course
 *                       中删除一个指定的6位课程编码
 *               备  注: 别忘记删除逗号
 * @param {CStudent} &student 需要拼接前置逗号
 * @return {*} 为真则成功
 */
bool CStudent::CancelCourse(const string &courseNumber) {

    // 未找到课程
    if (course.find(courseNumber) == string::npos) 
        return CInterface::CMSErrorReport("Cannot find course."); 

    // 得到子串首次出现的位置
    size_t pos = course.find(courseNumber); 

    // 删除匹配的子串
    course.erase(pos, 7); 
    
    return true; 
}

/**
 * @description: 显示选课结果
 * @param {*}
 * @return {*}
 */
bool CStudent::ShowMyCourseList() {
    string buffer; 
    vector<string> courseNumberList; 
    vector<CCourse> courseList; 
    stringstream ss(course); 

    // 原字符串以逗号分隔每个课程编码
    while (getline(ss, buffer, ',')) 
        if (buffer != "000000") courseNumberList.push_back(buffer); 

    // 遍历课程编码
    // 查询课程信息
    for (vector<string>::const_iterator iter = courseNumberList.cbegin();
                                        iter != courseNumberList.cend(); ++iter) {
        CData::QueCourseData(courseList, (*iter)); 
        // cout << (*iter) << endl; 
    }

    CInterface::CMSPrompt("请输入回车键以继续"); 
    CInterface::Flush(); 
    getchar(); 
    return true; 
}