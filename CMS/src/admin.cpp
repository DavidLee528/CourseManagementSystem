#include <iostream>
#include <string>

#include "admin.h"

using std::cout; 
using std::endl; 
using std::string; 

CAdmin::CAdmin(const string &_username): username(_username) {

    cout << "hello admin." << endl; 

}

CAdmin::CAdmin(const CAdmin &rhs) {

}

CAdmin::~CAdmin() {

}