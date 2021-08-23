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

bool CData::GetUserAuthorization(const std::pair<std::string, std::string> &user, int &authCode) {

    // TODO: 确定获取权限码的业务逻辑
    //  


    return true; 
}


