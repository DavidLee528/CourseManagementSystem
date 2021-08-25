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

string & CStudent::GetStudentUsername() {
    return username; 
}

string & CStudent::GetStudentName() {
    return name; 
}

string & CStudent::GetStudentMajor() {
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

