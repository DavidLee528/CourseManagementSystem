#include <iostream>
#include <string>

#include "../include/CMS.h"
#include "../include/course.h"

using std::cout; 
using std::string; 
using std::istream; 

CCourse::CCourse() {
    
}

CCourse::CCourse(const CCourse &rhs) {

}

CCourse::~CCourse() {

}

istream& operator>>(istream &is, CCourse &c) {
    string str; 
    size_t num; 
    cout << "课程编号："; is >> str; c.SetCourseNumber(str); 
    cout << "课程名称："; is >> str; c.SetCourseTitle(str); 
    cout << "必修选修："; is >> str; c.SetCourseAttribute(str); 
    cout << "总 时 长："; is >> num; c.SetTotalClassHours(num); 
    cout << "授课时长："; is >> num; c.SetTeachingHours(num); 
    cout << "实验时长："; is >> num; c.SetExperimentHours(num); 
    cout << "课程学分："; is >> num; c.SetCredit(num); 
    cout << "学    期："; is >> num; c.SetCourseSemester(num); 
}

const string & CCourse::GetCourseNumber() const {
    return courseNumber; 
}

const string & CCourse::GetCourseTitle() const {
    return courseTitle; 
}

const string & CCourse::GetCourseAttribute() const {
    return courseAttribute; 
}

const size_t CCourse::GetTotalClassHours() const {
    return totalClassHours; 
}
const size_t CCourse::GetTeachingHours() const {
    return teachingHours; 
}
const size_t CCourse::GetExperimentHours() const {
    return experimentHours; 
}

const size_t CCourse::GetCredit() const {
    return credit; 
}

const size_t CCourse::GetCourseSemester() const {
    return courseSemester; 
}

void CCourse::SetCourseNumber(const string &rhs) {
    courseNumber = rhs; 
}

void CCourse::SetCourseTitle(const string &rhs) {
    courseTitle = rhs; 
} 

void CCourse::SetCourseAttribute(const string &rhs) {
    courseAttribute = rhs; 
} 

void CCourse::SetTotalClassHours(const size_t rhs) {
    totalClassHours = rhs; 
} 

void CCourse::SetTeachingHours(const size_t rhs) {
    teachingHours = rhs; 
} 

void CCourse::SetExperimentHours(const size_t rhs) {
    experimentHours = rhs; 
} 

void CCourse::SetCredit(const size_t rhs) {
    credit = rhs; 
} 

void CCourse::SetCourseSemester(const size_t rhs) {
    courseSemester = rhs; 
} 
