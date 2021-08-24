#include <iostream>

#include "teacher.h"

using std::cout; 
using std::endl; 
using std::string; 

CTeacher::CTeacher(const string &_username): username(_username) {

    cout << "hello teacher. " << endl; 

}

CTeacher::CTeacher(const CTeacher &rhs) {

}

CTeacher::~CTeacher() {

}
