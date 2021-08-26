#include <iostream>
#include <string>

#include "../include/student.h"

using std::cout; 
using std::endl; 
using std::string; 

CStudent::CStudent() {
    
}

CStudent::CStudent(const string &_username): username(_username) { 

    cout << "hello student. " << endl; 

}

CStudent::CStudent(const CStudent &rhs) {

}

CStudent::~CStudent() {
    
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

/**
 * @description: 名  称: 选课
 *               调用者: CInterface类sMain函数
 *               功  能: 在CStudent类对象的私有数据成员course
 *                       后追加一个6位课程编码
 *               备  注: 000000,600001,600003,600008
 *                      初始字符串为000000
 *                      每次追加,xxxxxx
 * @param {CStudent} &student 
 * @return {*} 为真则成功
 */
bool CStudent::SelectCourse(CStudent &student) {

}

/**
 * @description: 退选课
 *               调用者: CInterface类sMain函数
 *               功  能: 在CStudent类对象的私有数据成员course
 *                       中删除一个指定的6位课程编码
 *               备  注: 别忘记删除逗号
 * @param {CStudent} &student
 * @return {*} 为真则成功
 */
bool CStudent::CancelCourse(CStudent &student) {

}