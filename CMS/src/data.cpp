/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 
 * @ E-mail: 13121515269@163.com
 */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>


#include "CMS.h"
#include "../include/interface.h"
#include "../include/data.h"

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

/**
 * @description: 此函数读取user.txt文件，验证密码有效性
 *               关联容器unordered_map底层使用哈希表，时间复杂度O(1)
 * @param {const} std 用户输入的密码（有待验证的密码）
 * @return {*} 为真则通过
 */
bool CData::CheckPasswordValidity(const std::pair<std::string, std::string> &input) {

    // 打开user.dat文件
    ifstream user_data(PSWD_FILE_PATH, ifstream::in); 
    if (!user_data.is_open()) return CInterface::DisplayErrorMessage("Cannot open file. "); 
    
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
        return CInterface::DisplayErrorMessage("Cannot find username in file 'user.dat'. "); 

    // 密码错误
    if ((*iter).second != input.second)
        return CInterface::DisplayErrorMessage("Wrong password. "); 
    
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
    else return CInterface::DisplayErrorMessage("Generate authorization code failed. "); 

    return true; 
}


