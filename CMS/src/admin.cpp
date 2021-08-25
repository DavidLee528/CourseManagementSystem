#include <iostream>
#include <string>
#include <vector>

#include "../include/CMS.h"
#include "../include/data.h"
#include "../include/interface.h"
#include "../include/admin.h"
#include "../include/student.h"
#include "../include/teacher.h"

using std::cout; 
using std::cin; 
using std::endl; 
using std::string; 
using std::vector; 

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
    cout << "[4] 查看教师" << endl; 
    cout << "[0] 返回上一级" << endl << endl; 
}

void CAdmin::ShowOptionsLv2_2() {
    system("clear"); 
    CInterface::CMSPrompt("你好, admin!"); 
    cout << endl << endl; 
    cout << "[1] 增加学生" << endl; 
    cout << "[2] 删除学生" << endl; 
    cout << "[3] 修改学生" << endl; 
    cout << "[4] 查看学生" << endl; 
    cout << "[0] 返回上一级" << endl << endl; 
}

void CAdmin::ShowOptionsLv2_3() {
    system("clear"); 
    CInterface::CMSPrompt("你好, admin!"); 
    cout << endl << endl; 
    cout << "[1] 增加课程" << endl; 
    cout << "[2] 删除课程" << endl; 
    cout << "[3] 修改课程" << endl; 
    cout << "[4] 查看课程" << endl; 
    cout << "[0] 返回上一级" << endl << endl; 
}

// ======================================================================= //
//                                教师管理                                  //
// ======================================================================= //


bool CAdmin::ManageTeacher() {
    
    while (1) {
        string userOption; 
        CAdmin::ShowOptionsLv2_1(); 
        CInterface::GetOption("Please select", userOption); 
        if (userOption == "1") {
            CAdmin::AddTeacher(); 
            continue; 
        } else if (userOption == "2") {
            CAdmin::DelTeacher(); 
            continue; 
        } else if (userOption == "3") {
            CAdmin::ModTeacher(); 
            continue; 
        } else if (userOption == "4") {
            CAdmin::QueTeacher(); 
            continue; 
        } else if (userOption == "0") {
            break; 
        } else {
            return CInterface::CMSErrorReport("In function ManageTeacher"); 
        }
    }
    
    return true; 
}

/**
 * @description: 增加一位教师
 * @param {*} 
 * @return {*}
 */
void CAdmin::AddTeacher() {
    CInterface::CMSPrompt("添加教师信息"); 
    CTeacher teacher; 
    cin >> teacher; 
    if (CData::AddTeacherData(teacher)) CInterface::CMSPrompt("添加成功, 输入任意键以继续管理教师..."); 
    else CInterface::CMSPrompt("添加失败"); 
    CInterface::Flush(); 
    getchar(); 
}

void CAdmin::DelTeacher() {
    CInterface::CMSPrompt("删除教师信息"); 
    CInterface::CMSPrompt("请输入教工号"); 
    string str; 
    cin >> str; 
    if (CData::DelTeacherData(str)) CInterface::CMSPrompt("删除成功，输入任意键以继续管理教师..."); 
    else CInterface::CMSPrompt("删除失败"); 
    CInterface::Flush(); 
    getchar(); 
}

void CAdmin::ModTeacher() {
    // 修改一位教师

}

void CAdmin::QueTeacher() {
    CInterface::CMSPrompt("查询教师信息, 请输入教工号(输入#以查询全部教师)"); 
    string str; cin >> str; 
    vector<CTeacher> teacherList; 
    if (str == "#") CData::QueTeacherData(teacherList); 
    else CData::QueTeacherData(teacherList, str); 
    // 打印
    cout << endl; 
    for (vector<CTeacher>::const_iterator iter = teacherList.cbegin(); iter != teacherList.cend(); ++iter) {
        cout << (*iter).GetTeacherUsername() << (*iter).GetTeacherName() << (*iter).GetTeacherMajor() << endl; 
    }
    
}


// ======================================================================= //
//                                学生管理                                  //
// ======================================================================= //

bool CAdmin::ManageStudent(const string &option) {
    if (option == "1") {
        CAdmin::AddStudent(); 
    } else if (option == "2") {
        CAdmin::DelStudent(); 
    } else if (option == "3") {
        CAdmin::ModStudent(); 
    } else if (option == "4") {
        CAdmin::QueStudent(); 
    } else {
        return CInterface::CMSErrorReport("In function ManageStudent"); 
    }
    return true; 
}

void CAdmin::AddStudent() {
    CStudent student; 
    string str; 
    CInterface::CMSPrompt("添加学生信息"); 
    cout << endl; 
    cout << "教工号："; cin >> str; student.SetStudentUsername(str); 
    cout << "密  码："; cin >> str; student.SetStudentPassword(str); 
    cout << "姓  名："; cin >> str; student.SetStudentName(str); 
    cout << "专  业："; cin >> str; student.SetStudentMajor(str); 
    if (CData::AddStudentData(student)) CInterface::CMSPrompt("添加成功"); 
    else CInterface::CMSPrompt("添加失败"); 
    CInterface::Flush(); 
    getchar(); 
    CInterface::Flush(); 
}

void CAdmin::DelStudent() {
    // 删除一名学生
}

void CAdmin::ModStudent() {
    // 修改一名学生
}

void CAdmin::QueStudent() {
    // 查询所有学生信息
}



// ======================================================================= //
//                                课程管理                                  //
// ======================================================================= //




