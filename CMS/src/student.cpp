#include <iostream>
#include <string>

#include "student.h"

using std::cout; 
using std::endl; 
using std::string; 

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