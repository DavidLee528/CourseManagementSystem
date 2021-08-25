#include <iostream>
#include <string>

#include "../include/CMS.h"
#include "../include/teacher.h"

using std::cout; 
using std::endl; 
using std::string; 
using std::istream; 
using std::ostream; 

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