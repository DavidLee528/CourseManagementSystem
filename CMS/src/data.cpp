#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>


#include "../include/CMS.h"
#include "../include/interface.h"
#include "../include/data.h"
#include "../include/teacher.h"
#include "../include/student.h"
#include "../include/admin.h"
#include "../include/course.h"

using std::ios; 
using std::ifstream; 
using std::ofstream; 
using std::fstream; 
using std::string; 
using std::stringstream; 
using std::unordered_map; 
using std::pair; 
using std::make_pair; 
using std::cout; 
using std::endl; 
using std::vector; 

/**
 * @description: 此函数读取user.txt文件，验证密码有效性
 *               关联容器unordered_map底层使用哈希表，时间复杂度O(1)
 * @param {const} std 用户输入的密码（有待验证的密码）
 * @return {*} 为真则通过
 */
bool CData::CheckPasswordValidity(const std::pair<std::string, std::string> &input) {

    // 打开user.dat文件
    ifstream user_data(PSWD_FILE_PATH, ifstream::in); 
    if (!user_data.is_open()) return CInterface::CMSErrorReport("Cannot open file. "); 
    
    // 读取user.dat文件
    // 使用关联容器unordered_map存储信息
    string line, username, password; 
    unordered_map<string, string> userlist; 
    while (getline(user_data, line)) {
        stringstream ssLine(line); 
        ssLine >> username >> password; 
        userlist.insert(make_pair(username, password)); 
    }

    // 得到迭代器
    unordered_map<string, string>::iterator iter = userlist.find(input.first); 

    // 未找到用户
    if (iter == userlist.end())
        return CInterface::CMSErrorReport("Cannot find username in file 'user.dat'. "); 

    // 密码错误
    if ((*iter).second != input.second)
        return CInterface::CMSErrorReport("Wrong password. "); 
    
    user_data.close(); 
    return true; 
}


/**
 * @description: 此函数根据username带出其对应的权限码
 * @param {pair<std::string, std::string>} &user username+password
 * @param {int} &authCode 权限码
 * @return {*} 为真则成功
 */
bool CData::GetUserAuthorization(const pair<string, string> &user, int &authCode) {

    string username = user.first; 
    // 学生
    if (username.length() == 11) authCode = STUDENT_AUTH_CODE; 
    // 老师
    else if (username.length() == 4 || username.length() == 6) authCode = TEACHER_AUTH_CODE; 
    // 管理员
    else if (username == "admin") authCode = ADMIN_AUTH_CODE;  
    // 不合法情况
    else return CInterface::CMSErrorReport("Generate authorization code failed. "); 

    return true; 
}

/**
 * @description: 录入一次密码
 * @param {string} &username 用户名
 * @return {*} 为真则成功
 */
bool CData::SetPassword(const string &username, const string &newPassword) {


}

/**
 * @description: 从文件中查找教师
 * @param {string} &username 教工号
 * @param {CTeacher} &teacher
 * @return {*} 为真则成功
 */
bool CData::FindTeacherByUsername(const string &username, CTeacher &teacher) {

    ifstream teacher_data(TEACHER_FILE_PATH, ios::in); 
    if (!teacher_data.is_open()) return CInterface::CMSErrorReport("Cannot open file."); 

    // TODO:
    // 若查找失败则函数返回值false
    // 文件数据样例已经保存在teacher.dat中
    // 

    teacher_data.close(); 
    return true; 
}

/**
 * @description: 从文件中查找学生
 * @param {string} &username 学号
 * @param {CStudent} &student
 * @return {*} 为真则成功
 */
bool CData::FindStudentByUsername(const string &username, CStudent &student) {

    ifstream student_data(STUDENT_FILE_PATH, ios::in); 
    if (!student_data.is_open()) return CInterface::CMSErrorReport("Cannot open file"); 

    // TODO:
    // 若查找失败则函数返回值false
    // 文件数据样例已经保存在student.dat中
    // 

    student_data.close(); 
    return true; 
}

/**
 * @description: 向文件以二进制写入一个教师信息
 *               需要检查教师是否重复
 * @param {CTeacher} &teacher CTeacher类对象
 * @return {*} 为真则成功
 */
bool CData::AddTeacherData(const CTeacher &teacher) {

    ofstream out(TEACHER_FILE_PATH, ios::app); 
    if (!out.is_open()) return CInterface::CMSErrorReport("Cannot open file."); 

    out << teacher.GetTeacherUsername() << " "; 
    out << teacher.GetTeacherName() << " "; 
    out << teacher.GetTeacherMajor() << " "; 
    out << endl << endl; 

    // SetPassword(teacher.GetTeacherUsername(), teacher.password); 

    out.close(); 
    return true; 
}

/**
 * @description: 向文件以二进制读取教师信息
 *               若没有指定username，则查询所有教师信息
 * @param {*}
 * @return {*}
 */
bool CData::QueTeacherData(vector<CTeacher> &teacherList, const string &username) {

    ifstream in(TEACHER_FILE_PATH, ios::in); 
    if (!in.is_open()) return CInterface::CMSErrorReport("Cannot open file."); 

    if (username == "$default$") {
        
    } else {
        CTeacher teacher; 
        FindByUsername(); 
        cout << teacher << endl; 
    }
    
    
    

    in.close(); 
    return true; 
}

/**
 * @description: 向文件以二进制写入一个学生信息
 *               需要检查学生是否重复
 * @param {CStudent} &student CStudent类对象
 * @return {*} 为真则成功
 */
bool CData::AddStudentData(const CStudent &student) {

}

