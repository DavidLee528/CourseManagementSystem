#include <iostream>

#include "teacher.h"

using std::cout; 
using std::endl; 
using std::string; 

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