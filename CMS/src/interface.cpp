#include <iostream>
#include <string>
#include <utility>
#include <unistd.h>

#include "../include/CMS.h"
#include "../include/interface.h"
#include "../include/data.h"
#include "admin.h"
#include "student.h"
#include "teacher.h"


using std::cin; 
using std::cout; 
using std::endl; 

void CInterface::rMain() {
    cout << "hello world" << endl; 
    return ;
}

bool CInterface::Login() {

    // 屏幕初始化
    if (!CInterface::InitScreen()) 
        return CInterface::DisplayErrorMessage("Failed to initialize the screen. "); 
    
    // 键盘输入用户名与密码
    std::string username, password; 
    if (!CInterface::UserInfoInput(username, password))
        return CInterface::DisplayErrorMessage("Fail to input username and password. "); 

    // 检查用户名与密码
    if (!CData::CheckPasswordValidity(std::make_pair(username, password)))
        return CInterface::DisplayErrorMessage("Invalid username or password. "); 

    // 生成权限码
    int authCode = -1; 
    if (!CData::GetUserAuthorization(std::make_pair(username, password), authCode))
        return CInterface::DisplayErrorMessage("Failed to get authorization. "); 
    if (authCode == -1)
        return CInterface::DisplayErrorMessage("Wrong authorization code. "); 
    
    // 创建用户对象
    // 保存用户信息
    if (authCode == ADMIN_AUTH_CODE)  CAdmin admin(username); 
    if (authCode == STUDENT_AUTH_CODE) CStudent student(username); 
    if (authCode == TEACHER_AUTH_CODE) CTeacher teacher(username); 
  
    return true; 
}

/**
 * @description: 从标准输入流中获取用户名和密码
 *               需要#include <unistd.h>
 *               调用getpass以达到密码输入无回显
 * @param {string} &username 用户名
 * @param {string} &password 密码
 * @return {*} 
 */
bool CInterface::UserInfoInput(std::string &username, std::string &password) {
    cout << "Username: "; 
    cin >> username; 
    password = getpass("Password: "); 
    return true; 
}

bool CInterface::InitScreen() {

    system("clear"); 
    cout << "Welcome to Course Management System. " << endl; 

    // TODO: 添加字符画CMS
    // 

    return true; 
}

bool CInterface::DisplayErrorMessage(const std::string &msg) {

    std::cerr << msg << endl; 

    return false; 
}