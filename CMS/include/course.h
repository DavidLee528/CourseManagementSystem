#ifndef _COURSE_H
#define _COURSE_H

using std::string; 

class CCourse {

private: 
    string courseNumber;            // 课程编号
    string courseTitle;             // 课程名称
    string courseAttribute;         // 课程属性：必修或选修
    size_t totalClassHours;         // 总学时
    size_t teachingHours;           // 授课学时
    size_t experimentHours;         // 实验或上机学时
    size_t credit;                  // 学分
    int courseSemester;             // 开课学期：秋季或春季

public:     

    CCourse(); 
    CCourse(const CCourse &rhs); 
    ~CCourse(); 

    // 接口
    string & GetCourseNumber(); 
    string & GetCourseTitle(); 
    string & GetCourseAttribute(); 
    size_t GetTotalClassHours(); 
    size_t GetTeachingHours(); 
    size_t GetExperimentHours(); 
    size_t GetCredit(); 
    int GetCourseSemester(); 




}; 


#endif