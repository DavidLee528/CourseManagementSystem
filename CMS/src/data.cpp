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

    switch (authCode) {
        case 1: 
            if (username.length() != 11) return false; 
            break; 
        case 2: 
            if (username.length() != 4 && username.length() != 6) return false; 
            break; 
        default: 
            return CInterface::CMSErrorReport("Wrong authCode."); 
            break; 
    }

    return true;
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
    unordered_map<string, string>::iterator pos = userlist.find(username); 

    // 若用户不存在, 增加一条用户记录
    // 若用户存在, 修改用户密码
    if (pos == userlist.end()) {
        userlist.insert(make_pair(username, newPassword)); 
    } else {
        (*pos).second = newPassword;
    }

    // 关闭后打开并清空文件内容
    user_data.close();
    ofstream outfile(PSWD_FILE_PATH, ofstream::out | ofstream::trunc);
    
    // 写入修改后的内容
    for (unordered_map<string, string>::const_iterator iter = userlist.cbegin(); iter != userlist.cend(); ++iter) {
        outfile << (*iter).first << " " << (*iter).second << "\n"; 
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
    // 打开user.dat文件
    ifstream user_data(PSWD_FILE_PATH, ios::in); 
    if (!user_data.is_open()) return CInterface::CMSErrorReport("Cannot open file"); 
    
    // 读取user.dat文件
    // 使用关联容器unordered_map存储信息
    string line, _username, _password;
    unordered_map <string, string> userlist;
    while (getline(user_data, line)) {
        stringstream ssLine(line);
        ssLine >> _username >> _password;
        userlist.insert(make_pair(_username, _password));
    }

    // 未找到用户
    if(userlist.find(username) == userlist.end()) 
	return CInterface::CMSErrorReport("Cannot find username in file 'user.dat'. "); 
	
    // 删除元素 
    userlist.erase(username);
	
    // 关闭后打开并清空文件内容
    user_data.close();
    ofstream outfile(PSWD_FILE_PATH, ofstream::out | ofstream::trunc);
    if (!outfile.is_open()) return CInterface::CMSErrorReport("Cannot open file");
    
    // 写入修改后的内容
    for (auto iter = userlist.begin(); iter != userlist.end(); iter++) {
        outfile << iter->first << " " << iter->second << endl;
    }

    outfile.close();
    return true;
	
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
    ofstream teacherData(TEACHER_FILE_PATH, ios::app); 
    if (!teacherData.is_open()) return CInterface::CMSErrorReport("Cannot open file."); 

    // 检查是否重复添加
    CTeacher t; 
    if (CData::FindTeacherByUsername(teacher.GetTeacherUsername(), t)) 
        return CInterface::CMSErrorReport("Teacher exist."); 
    
    // 检查用户名格式合法性
    if (!CData::CheckUsernameFormat(teacher.GetTeacherUsername(), TEACHER_AUTH_CODE)) 
        return CInterface::CMSErrorReport("Wrong username format"); 

    // 向teacher.dat增加一条教师信息
    teacherData << teacher.GetTeacherUsername() << " "; 
    teacherData << teacher.GetTeacherName() << " "; 
    teacherData << teacher.GetTeacherMajor() << "\n"; 

    // 向user.dat增加一条用户记录
    SetPassword(teacher.GetTeacherUsername(), teacher.password); 

    teacherData.close(); 
    return true; 
}

/**
 * @description: 从文件删除一个教师信息
 * @param {string} &username 教工号
 * @return {*} 为真则成功
 */
bool CData::DelTeacherData(const string &username) {

    // 初始化
    ifstream teacherData(TEACHER_FILE_PATH, ios::in); 
    if (!teacherData.is_open()) return CInterface::CMSErrorReport("Cannot open file."); 

    // 删除user.dat中的用户记录
    CData::DelPassword(username); 
    
    // 读取teacher.dat文件
    // 将全部文件存入内存(跳删除用户)过待
    
    vector<vector<string> > teacherList; 
    string line, _username, password, name, major; 
    while (getline(teacherData, line)) {
        stringstream ssLine(line); 
        ssLine >> _username >> password >> name >> major; 
        // 跳过待删除用户
        if (username == _username) continue; 
        vector<string> elem{_username, password, name, major}; 
        teacherList.push_back(elem); 
    }

    // 清空文件内容
    teacherData.close(); 
    ofstream newTeacherData(TEACHER_FILE_PATH, ios::out | ios::trunc); 
    if (!newTeacherData.is_open()) return CInterface::CMSErrorReport("Cannot open file."); 
    
    // 向文件写入内容
    for (vector<vector<string> >::const_iterator iter = teacherList.cbegin(); iter != teacherList.cend(); ++iter) {
        newTeacherData << (*iter)[0] << " " << (*iter)[1] << " " << (*iter)[2] << "\n"; 
    }

    newTeacherData.close(); 
    return true; 
}

/**
 * @description: 修改教师信息
 * @param {CTeacher} &teacher
 * @param {string} &username
 * @return {*} 为真则修改成功
 */
bool CData::ModTeacherData(const CTeacher &teacher, const string &username) {

    // 初始化
    ifstream teacherData(TEACHER_FILE_PATH, ios::in); 
    if (!teacherData.is_open()) return CInterface::CMSErrorReport("Cannot open file."); 

    // 修改user.dat中的用户记录
    CData::SetPassword(username, teacher.password); 
    
    // 读取teacher.dat文件
    // 使用关联容器unordered_map存储信息
    vector<string> elem; 
    vector<vector<string> > teacherList; 
    string line, _username, password, name, major; 
    while (getline(teacherData, line)) {
        stringstream ssLine(line); 
        ssLine >> _username >> password >> name >> major; 
        // 修改用户信息
        if (username == _username) {
            _username = teacher.username; 
            name = teacher.name; 
            major = teacher.major; 
        }
        vector<string> elem{_username, name, major}; 
        teacherList.push_back(elem); 
}

    // 清空文件内容
    teacherData.close(); 
    ofstream newTeacherData(TEACHER_FILE_PATH, ios::out | ios::trunc); 
    if (!newTeacherData.is_open()) return CInterface::CMSErrorReport("Cannot open file."); 
    
    // 向文件写入内容
    for (vector<vector<string> >::const_iterator iter = teacherList.cbegin(); iter != teacherList.cend(); ++iter) {
        newTeacherData << (*iter)[0] << " " << (*iter)[1] << " " << (*iter)[2] << "\n"; 
    }

    newTeacherData.close(); 
    return true; 
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

