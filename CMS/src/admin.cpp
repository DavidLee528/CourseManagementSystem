#include <iostream>
#include <string>
#include <vector>

#include "../include/CMS.h"
#include "../include/data.h"
#include "../include/interface.h"
#include "../include/admin.h"
#include "../include/student.h"
#include "../include/teacher.h"
#include "../include/course.h"

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
    #ifndef DEBUG 
    system("clear"); 
    #endif
    CInterface::CMSPrompt("你好, admin!"); 
    cout << endl << endl; 
    cout << " [1] 教师管理" << endl; 
    cout << " [2] 学生管理" << endl; 
    cout << " [3] 课程管理" << endl; 
    cout << " [0] 退出系统" << endl << endl; 
}

void CAdmin::ShowOptionsLv2_1() {
    #ifndef DEBUG 
    system("clear"); 
    #endif
    CInterface::CMSPrompt("你好, admin!"); 
    cout << endl << endl; 
    cout << "[1] 增加教师" << endl; 
    cout << "[2] 删除教师" << endl; 
    cout << "[3] 修改教师" << endl; 
    cout << "[4] 查看教师" << endl; 
    cout << "[0] 返回上一级" << endl << endl; 
}

void CAdmin::ShowOptionsLv2_2() {
    #ifndef DEBUG 
    system("clear"); 
    #endif
    CInterface::CMSPrompt("你好, admin!"); 
    cout << endl << endl; 
    cout << "[1] 增加学生" << endl; 
    cout << "[2] 删除学生" << endl; 
    cout << "[3] 修改学生" << endl; 
    cout << "[4] 查看学生" << endl; 
    cout << "[0] 返回上一级" << endl << endl; 
}

void CAdmin::ShowOptionsLv2_3() {
    #ifndef DEBUG 
    system("clear"); 
    #endif
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

void CAdmin::AddTeacher() {
    CInterface::CMSPrompt("添加教师信息"); 
    CTeacher course; 
    cin >> course; 
    if (CData::AddTeacherData(course)) CInterface::CMSPrompt("添加成功, 输入任意键以继续管理教师..."); 
    else CInterface::CMSErrorReport("添加失败"); 
    CInterface::Flush(); 
    getchar(); 
}

void CAdmin::DelTeacher() {
    CInterface::CMSPrompt("删除教师信息，请输入教工号"); 
    string str; 
    cin >> str; 
    if (CData::DelTeacherData(str)) CInterface::CMSPrompt("删除成功，输入任意键以继续管理教师..."); 
    else CInterface::CMSErrorReport("删除失败"); 
    CInterface::Flush(); 
    getchar(); 
}

void CAdmin::ModTeacher() {
    // 修改一位教师
    CInterface::CMSPrompt("修改教师信息"); 
    CTeacher course; 
    cin >> course; 
    if (CData::ModTeacherData(course, course.GetTeacherUsername())) CInterface::CMSPrompt("修改成功，输入任意键以继续管理教师..."); 
    else CInterface::CMSErrorReport("删除失败"); 
    getchar(); 
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
        cout << (*iter).GetTeacherUsername() << " " << (*iter).GetTeacherName() << " " << (*iter).GetTeacherMajor() << endl; 
    }
    cout << endl; 
    CInterface::CMSPrompt("输入任意键以继续管理教师..."); 
    CInterface::Flush(); 
    getchar(); 
}


// ======================================================================= //
//                                学生管理                                  //
// ======================================================================= //

bool CAdmin::ManageStudent() {
    // if (option == "1") {
    //     CAdmin::AddStudent(); 
    // } else if (option == "2") {
    //     CAdmin::DelStudent(); 
    // } else if (option == "3") {
    //     CAdmin::ModStudent(); 
    // } else if (option == "4") {
    //     CAdmin::QueStudent(); 
    // } else {
    //     return CInterface::CMSErrorReport("In function ManageStudent"); 
    // }
    // return true; 
}

void CAdmin::AddStudent() {
    // 添加一名学生
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


bool CAdmin::ManageCourse() {
    
    while (1) {
        string userOption; 
        CAdmin::ShowOptionsLv2_3(); 
        CInterface::GetOption("Please select", userOption); 
        if (userOption == "1") {
            CAdmin::AddCourse(); 
            continue; 
        } else if (userOption == "2") {
            CAdmin::DelCourse(); 
            continue; 
        } else if (userOption == "3") {
            CAdmin::ModCourse(); 
            continue; 
        } else if (userOption == "4") {
            CAdmin::QueCourse(); 
            continue; 
        } else if (userOption == "0") {
            break; 
        } else {
            return CInterface::CMSErrorReport("In function ManageCourse"); 
        }
    }
    
    return true; 
}

void CAdmin::AddCourse() {
    CInterface::CMSPrompt("添加课程信息"); 
    CCourse course; 
    cin >> course; 
    if (CData::AddCourseData(course)) CInterface::CMSPrompt("添加成功, 输入任意键以继续管理课程..."); 
    else CInterface::CMSErrorReport("添加失败"); 
    CInterface::Flush(); 
    getchar(); 
}

void CAdmin::DelCourse() {
    CInterface::CMSPrompt("删除课程信息，请输入课程编号"); 
    string str; 
    cin >> str; 
    if (CData::DelCourseData(str)) CInterface::CMSPrompt("删除成功，输入任意键以继续管理课程..."); 
    else CInterface::CMSErrorReport("删除失败"); 
    CInterface::Flush(); 
    getchar(); 
}

void CAdmin::ModCourse() {
    // 修改一位教师
    CInterface::CMSPrompt("修改课程信息"); 
    CCourse course; 
    cin >> course; 
    if (CData::ModCourseData(course)) CInterface::CMSPrompt("修改成功，输入任意键以继续管理课程..."); 
    else CInterface::CMSErrorReport("删除失败"); 
    CInterface::Flush(); 
    getchar(); 
}

void CAdmin::QueCourse() {
    CInterface::CMSPrompt("查询课程信息, 请输入课程编号(输入#以查询全部课程)"); 
    string str; cin >> str; 
    vector<CCourse> courseList; 
    if (str == "#") CData::QueCourseData(courseList); 
    else CData::QueCourseData(courseList, str); 
    // 打印
    // cout << endl; 
    // for (vector<CCourse>::const_iterator iter = courseList.cbegin(); iter != courseList.cend(); ++iter) {
    //     cout << (*iter).GetCourseNumber() << " ";  
    //     cout << (*iter).GetCourseTitle() << " ";   
    //     cout << (*iter).GetCourseAttribute() << " ";   
    //     cout << (*iter).GetTotalClassHours() << " ";   
    //     cout << (*iter).GetTeachingHours() << " ";   
    //     cout << (*iter).GetExperimentHours() << " ";   
    //     cout << (*iter).GetCredit() << " ";   
    //     cout << (*iter).GetCourseSemester() << "\n";  
    // }
    // cout << endl; 
    CInterface::CMSPrompt("输入任意键以继续管理课程..."); 
    CInterface::Flush(); 
    getchar(); 
}

