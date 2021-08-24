#include <iostream>
#include <string>

#include "CMS.h"
#include "admin.h"

using std::cout; 
using std::cin; 
using std::endl; 
using std::string; 

CAdmin::CAdmin(const string &_username): username(_username) {

    cout << "hello admin." << endl; 

}

CAdmin::CAdmin(const CAdmin &rhs) {

}

CAdmin::~CAdmin() {

}

void CAdmin::ShowOptionsLv1() {
    cout << " [1] 教师管理" << endl; 
    cout << " [2] 学生管理" << endl; 
    cout << " [3] 课程管理" << endl; 
    cout << " [0] 退出系统" << endl; 
}

void CAdmin::ShowOptionsLv2_1() {
    cout << "[1] 增加教师" << endl; 
    cout << "[2] 删除教师" << endl; 
    cout << "[3] 修改教师" << endl; 
    cout << "[4] 查看所有教师" << endl; 
    cout << "[0] 返回上一级" << endl; 
}

void CAdmin::ShowOptionsLv2_2() {
    cout << "[1] 增加学生" << endl; 
    cout << "[2] 删除学生" << endl; 
    cout << "[3] 修改学生" << endl; 
    cout << "[4] 查看所有学生" << endl; 
    cout << "[0] 返回上一级" << endl; 
}

void CAdmin::ShowOptionsLv2_3() {
    cout << "[1] 增加课程" << endl; 
    cout << "[2] 删除课程" << endl; 
    cout << "[3] 修改课程" << endl; 
    cout << "[4] 查看所有课程" << endl; 
    cout << "[0] 返回上一级" << endl; 
}

