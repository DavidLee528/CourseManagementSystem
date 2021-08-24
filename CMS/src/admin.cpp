#include <iostream>
#include <string>

#include "CMS.h"
#include "data.h"
#include "interface.h"
#include "admin.h"

using std::cout; 
using std::cin; 
using std::endl; 
using std::string; 

CAdmin::CAdmin(const string &_username): username(_username) {

}

CAdmin::CAdmin(const CAdmin &rhs) {

}

CAdmin::~CAdmin() {

}

void CAdmin::ShowOptionsLv1() {
    system("clear"); 
    CInterface::CMSPrompt("你好, admin!"); 
    cout << endl << endl; 
    cout << " [1] 教师管理" << endl; 
    cout << " [2] 学生管理" << endl; 
    cout << " [3] 课程管理" << endl; 
    cout << " [0] 退出系统" << endl << endl; 
}

void CAdmin::ShowOptionsLv2_1() {
    system("clear"); 
    CInterface::CMSPrompt("你好, admin!"); 
    cout << endl << endl; 
    cout << "[1] 增加教师" << endl; 
    cout << "[2] 删除教师" << endl; 
    cout << "[3] 修改教师" << endl; 
    cout << "[4] 查看所有教师" << endl; 
    cout << "[0] 返回上一级" << endl << endl; 
}

void CAdmin::ShowOptionsLv2_2() {
    system("clear"); 
    CInterface::CMSPrompt("你好, admin!"); 
    cout << endl << endl; 
    cout << "[1] 增加学生" << endl; 
    cout << "[2] 删除学生" << endl; 
    cout << "[3] 修改学生" << endl; 
    cout << "[4] 查看所有学生" << endl; 
    cout << "[0] 返回上一级" << endl << endl; 
}

void CAdmin::ShowOptionsLv2_3() {
    system("clear"); 
    CInterface::CMSPrompt("你好, admin!"); 
    cout << endl << endl; 
    cout << "[1] 增加课程" << endl; 
    cout << "[2] 删除课程" << endl; 
    cout << "[3] 修改课程" << endl; 
    cout << "[4] 查看所有课程" << endl; 
    cout << "[0] 返回上一级" << endl << endl; 
}


bool CAdmin::ManageTeacher(const string &option) {
    if (option == "1") {
        CAdmin::AddTeacher(); 
    } else if (option == "2") {
        CAdmin::DelTeacher(); 
    } else if (option == "3") {
        CAdmin::ModTeacher(); 
    } else if (option == "4") {
        CAdmin::QueTeacher(); 
    } else {
        return CInterface::CMSErrorReport("In function ManageTeacher"); 
    }
}

/**
 * @description: 增加一位教师
 * @param {*} 
 * @return {*}
 */
void CAdmin::AddTeacher() {
    CTeacher teacher; 
    string str; 
    CInterface::CMSPrompt("添加教师信息"); 
    cout << endl; 
    cout << "教工号："; cin >> str; teacher.SetTeacherUsername(str); 
    cout << "密  码："; cin >> str; teacher.SetTeacherPassword(str); 
    cout << "姓  名："; cin >> str; teacher.SetTeacherName(str); 
    cout << "专  业："; cin >> str; teacher.SetTeacherMajor(str); 
    if (CData::AddTeacherData(teacher)) CInterface::CMSPrompt("添加成功"); 
    else CInterface::CMSPrompt("添加失败"); 
}

void CAdmin::DelTeacher() {
    // 删除一位教师
}

void CAdmin::ModTeacher() {
    // 修改一位教师
}

void CAdmin::QueTeacher() {
    // 查询所有教师信息
}