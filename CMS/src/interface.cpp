#include <iostream>
#include <string>
#include <utility>
#include <ctime>
#include <execinfo.h>

#include "../include/CMS.h"
#include "../include/interface.h"
#include "../include/data.h"
#include "../include/admin.h"
#include "../include/student.h"
#include "../include/teacher.h"

#ifdef _WIN32
#include <conio.h>
#else 
#include <unistd.h>
#endif


using std::cin; 
using std::cout; 
using std::endl; 
using std::cerr; 
using std::string; 

/**
 * @description: 
 * @param {string} &msg
 * @return {*}
 */
bool CInterface::CMSErrorReport(const std::string &msg) {

    
    std::cerr << msg << endl; 
    
    // int j, nptrs; 
    // void *buffer[100]; 
    // char **strings; 
    // nptrs = backtrace(buffer, 100); 
    // printf(RED "[ CMS ERROR ]" NONE "backtrace() returned %d addresses\n", nptrs); 

    return false; 
}


/**
 * @description: 用户登录验证
 *               划分用户角色
 *               用户分流进入不同的主要函数
 * @param {*} void
 * @return {*} 为真则登录成功
 */
bool CInterface::Login() {

    // 屏幕初始化
    if (!CInterface::InitScreen()) 
        return CInterface::CMSErrorReport("Failed to initialize the screen. "); 
    
    // 键盘输入用户名与密码
    std::string username, password; 
    if (!CInterface::UserInfoInput(username, password))
        return CInterface::CMSErrorReport("Fail to input username and password. "); 

    // 检查用户名与密码
    if (!CData::CheckPasswordValidity(std::make_pair(username, password)))
        return CInterface::CMSErrorReport("Invalid username or password. "); 

    // 生成权限码
    int authCode = -1; 
    if (!CData::GetUserAuthorization(std::make_pair(username, password), authCode))
        return CInterface::CMSErrorReport("Failed to get authorization. "); 
    if (authCode == -1)
        return CInterface::CMSErrorReport("Wrong authorization code. "); 
    
    // 创建用户对象
    // 保存用户信息
    if (authCode == ADMIN_AUTH_CODE)  {
        CAdmin admin(username); 
        aMain(admin); 
    }
    if (authCode == STUDENT_AUTH_CODE) {
        CStudent student(username); 
        sMain(student); 
    }
    if (authCode == TEACHER_AUTH_CODE) {
        CTeacher teacher(username); 
        tMain(teacher); 
    }
  
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
    #ifdef _WIN32
        WindowsGetPass("Password: ", password); 
    #else
        password = getpass("Password: "); 
    #endif
    return true; 
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 */
bool CInterface::InitScreen() {

    system("clear"); 
    cout << "Welcome to Course Management System. " << endl; 

    // TODO: 添加字符画CMS
    // 

    return true; 
}


void CInterface::aMain(CAdmin &admin) {
    while (1) {
        // 用户选项初始化
        string userOption = "#"; 
        CAdmin::ShowOptionsLv1(); 
        CInterface::GetOption("Please select", userOption); 
        if (userOption == "1") {
            // 管理教师
            CAdmin::ManageTeacher(); 
            continue; 
        } else if (userOption == "2") {
            // 管理学生
            CAdmin::ManageStudent(); 
            continue; 
        } else if (userOption == "3") {
            // 管理课程
            CAdmin::ManageCourse(); 
            continue; 
        } else if (userOption == "0") {
            // 退出系统
            CInterface::Flush(); 
            CMSPrompt("Press any key to exit..."); 
            getchar(); 
            return ; 
        } else {
            cout << "_default" << endl; 
            continue; 
        }   
        break;   
    }
}


void CInterface::sMain(CStudent &student) {
    while (1) {
        string userOption = "#"; 
        CStudent::ShowOptionsLv1(student); 
        CInterface::GetOption("Please select", userOption); 
        if (userOption == "1") {
            // 查询个人信息
            CInterface::CMSPrompt("查询个人信息"); 
            student.ShowMyInfo(); 
            continue; 
        } else if (userOption == "2") {
            // 修改个人密码
            CInterface::CMSPrompt("请输入新密码："); 
            string num; cin >> num; 
            student.ChangePass(num); 
            continue; 
        } else if (userOption == "3") {
            // 选课
            CData::QueCourseData(); 
            CInterface::CMSPrompt("请输入课程编码: "); 
            string num; cin >> num; 
            num = "," + num; 
            student.SelectCourse(num); 
            continue; 
        } else if (userOption == "4") {
            // 查看选课结果
            CInterface::CMSPrompt("查看您的选课结果"); 
            student.ShowMyCourseList(); 
            continue; 
        } else if (userOption == "5") {
            // 退选
            CInterface::CMSPrompt("请输入退选课课程编码: "); 
            string num; cin >> num; 
            num = "," + num; 
            student.CancelCourse(num); 
            continue; 
        } else if (userOption == "0") {
            // 退出系统
            CInterface::Flush(); 
            CMSPrompt("Press any key to exit..."); 
            getchar(); 
            return ; 
        } else {
            cout << "_default" << endl; 
            continue; 
        }

        break;   
    }
}


void CInterface::tMain(CTeacher &teacher) {
    while (1) {
        // 用户选项初始化
        string userOption = "#"; 
        CTeacher::ShowOptionsLv1(teacher); 
        CInterface::GetOption("Please select", userOption); 
        if (userOption == "1") {
            // 查看个人信息
            CTeacher::QueInfo(teacher); 
            continue; 
        } else if (userOption == "2") {
            // 修改个人密码
            CTeacher::ModPassword(teacher); 
            continue; 
        } else if (userOption == "3") {
            // 查看课程列表
            CTeacher::QueCourseList(); 
            continue; 
        } else if (userOption == "4") {
            // 查看学生列表
            CTeacher::QueStudentList(); 
            continue; 
        } else if (userOption == "0") {
            // 退出系统
            CInterface::Flush(); 
            CMSPrompt("Press any key to exit..."); 
            getchar(); 
            return ; 
        } else {
            cout << "_default" << endl; 
            continue; 
        }   
        break;   
    }
}

void CInterface::GetOption(const string &prompt, string& option) {
    CInterface::CMSPrompt(prompt); 
    cin >> option; 
}

void CInterface::CMSPrompt(const string &prompt) {
    cout << GREEN << SOFTWARE_TITLE << NONE << BLUE << prompt << NONE << "  " << endl; 
}

#ifdef _WIN32
string & CInterface::WindowsGetPass(const std::string prompt, std::string& _password) {
    char ch;
    int index = 0;
    char password[50];

    cout << "Password: ";
    while ((ch = _getch()) != '\r') {
        if (ch != '\b') {
            printf("*");
            password[index++] = ch;
        }
        else {
            printf("\b \b");
            index--;
        }
    }
    password[index] = '\0';

    _password = password;
}
#endif

/**
 * @description: 清空缓冲区
 * @param {*} void
 * @return {*} void
 */
void CInterface::Flush() {
    char ch; 
    while ((ch = getchar()) != '\n' && ch != EOF)
        ; 
}

/**
 * @description: 获取当前日期
 * @param {*} void
 * @return {*} 返回一个string对象，格式如"2021年8月24日下午"
 */
// string & CInterface::GetDate(string &time) {
     
//     struct tm *local;
// 	time_t t = time(0);
	
// 	char tmp[64];
// 	strftime(tmp, sizeof(tmp), "%Y年%m月%d日",localtime(&t) );
// 	time = tmp;
	
// 	int h;
// 	char hours[20];
// 	strftime(hours, sizeof(hours), "%H", localtime(&t));
// 	h = atoi(hours);
	
// 	if (h < 5) time += "凌晨";
// 	else if (h < 8) time += "早晨"; 
// 	else if (h < 11) time += "上午";
// 	else if (h < 13) time += "中午";
// 	else if (h < 16) time += "下午";
// 	else if (h < 19) time += "傍晚";
// 	else if (h < 24) time += "晚上";
	
// 	return time;
// }
