#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>


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
using std::map; 
using std::unordered_map; 
using std::pair; 
using std::make_pair; 
using std::cout; 
using std::endl; 
using std::vector; 
using std::sort; 

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
 * @description: 检查用户名格式合法性，合法性检查规则见函数CData::GetUserAuthorization()
 *               根据authCode判断用户角色，见CMS.h     
 * @param {string} &username 待检查用户名
 * @param {int} authCode 用户权限码
 * @return {*} 合法则返回值为真
 */
bool CData::CheckUsernameFormat(const string &username, const int authCode) {

    // TODO: 检查用户名格式合法性
    // 

}

/**
 * @description: 录入一次密码
 * @param {string} &username 用户名
 * @return {*} 为真则成功
 */
bool CData::SetPassword(const string& username, const string& newPassword){
    // 打开user.dat文件
    ifstream user_data(PSWD_FILE_PATH, ifstream::in);
    if (!user_data.is_open()) return CInterface::CMSErrorReport("Cannot open file");

    // 读取user.dat文件
    // 使用关联容器unordered_map存储信息
    string line, _username, _password;
    unordered_map<string, string> userlist;
    while (getline(user_data, line)) {
        stringstream ssLine(line);
        ssLine >> _username >> _password;
        userlist.insert(make_pair(_username, _password));
    }
    // 得到迭代器
    unordered_map<string, string>::iterator iter = userlist.find(username); 

    // 用户不存在
    // 增加一条用户记录
    if (iter == userlist.end()) {
        userlist.insert(make_pair(username, newPassword)); 
        return true; 
    }

    // 修改
    iter->second = newPassword;

    // 关闭后打开并清空文件内容
    user_data.close();
    ofstream outfile;
    outfile.open(PSWD_FILE_PATH, ofstream::out | ofstream::trunc);

    // 写入修改后的内容
    for (iter = userlist.begin(); iter != userlist.end(); iter++) {
        outfile << iter->first << " " << iter->second << endl;
    }

    outfile.close();
    return true;
}

/**
 * @description: 从文件user.dat中删去一组用户, 即删去一整行
 * @param {string} &username 需要删除的用户名
 * @return {*} 删除成功则返回值为真
 */
bool CData::DelPassword(const string &username) {

    // TODO:
    // 

}

/**
 * @description: 从文件user.dat中判断username是否唯一
 * @param {string} &username 需要检查的username
 * @return {*} 唯一则返回值为真
 */
bool CData::IsUniqueUser(const string &username) {

    // TODO:
    // 

}


/**
 * @description: 从文件中查找教师
 * @param {string} &username 教工号
 * @param {CTeacher} &teacher
 * @return {*} 为真则成功，否则未找到
 */
bool CData::FindTeacherByUsername(const string &username, CTeacher &teacher) {
	int flag = 0;
    ifstream teacher_data(TEACHER_FILE_PATH, ios::in); 
    if (!teacher_data.is_open()) return CInterface::CMSErrorReport("Cannot open file"); 
    
    string line, _username, _name, _major;
    while (getline(teacher_data, line)) {
        stringstream ssLine(line);
        ssLine >> _username >> _name >> _major;
        
        if (username == _username) {
	   	    teacher.SetTeacherUsername(_username);
	    	teacher.SetTeacherName(_name);
	    	teacher.SetTeacherMajor(_major);
	    	flag = 1;
	    	break;
		}
	}
	if (flag == 0) return false;
	
    teacher_data.close(); 
    return true; 
}

/**
 * @description: 从文件中查找学生
 * @param {string} &username 学号
 * @param {CStudent} &student
 * @return {*} 为真则成功, 否则未找到
 */
bool CData::FindStudentByUsername(const string &username, CStudent &student) {
    
	int flag = 0;
    ifstream student_data(STUDENT_FILE_PATH, ios::in); 
    if (!student_data.is_open()) return CInterface::CMSErrorReport("Cannot open file"); 
    
    string line, _username, _name, _major;
    while (getline(student_data, line)) {
        stringstream ssLine(line);
        ssLine >> _username >> _name >> _major;
        
        if (username == _username){
	   	    student.SetStudentUsername(_username);
	    	student.SetStudentName(_name);
	    	student.SetStudentMajor(_major);
	    	flag = 1;
	    	break;
		}
	}
	if (flag == 0) return false;
	
    student_data.close(); 
    return true; 
}

/**
 * @description: 向文件写入一个教师信息
 *               需要检查教师是否重复
 * @param {CTeacher} &teacher CTeacher类对象
 * @return {*} 为真则成功
 */
bool CData::AddTeacherData(const CTeacher &teacher) {

    // 初始化文件
    // 检查新增教师是否重复
    ofstream out(TEACHER_FILE_PATH, ios::app); 
    CTeacher t; 
    if (!out.is_open()) return CInterface::CMSErrorReport("Cannot open file."); 
    if (CData::FindTeacherByUsername(teacher.GetTeacherUsername(), t)) return CInterface::CMSErrorReport("Teacher exist."); 

    // 向teacher.dat增加一条教师信息
    out << teacher.GetTeacherUsername() << " "; 
    out << teacher.GetTeacherName() << " "; 
    out << teacher.GetTeacherMajor() << " "; 
    out << endl << endl; 

    // 向user.dat增加一条用户记录
    SetPassword(teacher.GetTeacherUsername(), teacher.password); 

    out.close(); 
    return true; 
}

/**
 * @description: 从文件删除一个教师信息
 * @param {string} &username 教工号
 * @return {*} 为真则成功
 */
bool CData::DelTeacherData(const string &username) {



}

/**
 * @description: 从文件读取教师信息
 *               若没有指定username，则查询所有教师信息
 * @param {*} 使用可变长数组teacherList带出教师数据
 * @return {*} 为真则成功
 */
bool CData::QueTeacherData(vector<CTeacher> &teacherList, const string &username) {

    // 初始化输入文件流
    // 检查参数错误
    ifstream in(TEACHER_FILE_PATH, ios::in); 
    if (!in.is_open()) return CInterface::CMSErrorReport("Cannot open file."); 
    if (username.empty()) return CInterface::CMSErrorReport("Empty username."); 
    if (!teacherList.empty()) teacherList.clear(); 

    // 用户名为默认参数时，查询全部教师信息
    // 用户名非默认参数时，查询用户名对应的教师信息
    if (username == "$default$") {
        // 读取teacher.dat
        string line, _username, _name, _major; 
        vector<vector<string> > sVec; 
        vector<string> element; 
        while (getline(in, line)) {
            stringstream ssLine(line); 
            ssLine >> _username >> _name >> _major; 
            element.clear(); 
            element.push_back(_username); 
            element.push_back(_name); 
            element.push_back(_major); 
            sVec.push_back(element); 
        }
        // 根据username排序
        sort(sVec.begin(), sVec.end(), [](const vector<string> &lhs, const vector<string> &rhs) {
            if (lhs[0].length() != rhs[0].length()) return lhs[0].length() < rhs[0].length(); 
            return lhs[0] < rhs[0]; 
        }); 
        // 遍历带出
        CTeacher teacher; 
        for (vector<vector<string> >::const_iterator iter = sVec.cbegin(); iter != sVec.cend(); ++iter) {
            teacher.SetTeacherUsername((*iter)[0]); 
            teacher.SetTeacherName((*iter)[1]); 
            teacher.SetTeacherMajor((*iter)[2]); 
            teacherList.push_back(teacher); 
        }
    } else {
        CTeacher teacher; 
        FindTeacherByUsername(username, teacher); 
        teacherList.push_back(teacher); 
    }
    
    in.close(); 
    return true; 
}

/**
 * @description: 向文件写入一个学生信息
 *               需要检查学生是否重复
 * @param {CStudent} &student CStudent类对象
 * @return {*} 为真则成功
 */
bool CData::AddStudentData(const CStudent &student) {

}

