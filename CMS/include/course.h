#ifndef _COURSE_H
#define _COURSE_H

using std::string; 
using std::istream; 

class CCourse {

private: 
    string courseNumber;            // 课程编号
    string courseTitle;             // 课程名称
    string courseAttribute;         // 课程属性：必修或选修
    size_t totalClassHours;         // 总学时
    size_t teachingHours;           // 授课学时
    size_t experimentHours;         // 实验或上机学时
    size_t credit;                  // 学分
    size_t courseSemester;          // 开课学期：秋季或春季(1或2)

public:     

    CCourse(); 
    CCourse(const CCourse &rhs); 
    ~CCourse(); 

    friend istream& operator>>(istream &is, CCourse &c);     

public: 

    // 接口
    const string & GetCourseNumber() const;  
    const string & GetCourseTitle() const;  
    const string & GetCourseAttribute() const;  
    const size_t GetTotalClassHours() const;  
    const size_t GetTeachingHours() const;  
    const size_t GetExperimentHours() const;  
    const size_t GetCredit() const;  
    const size_t GetCourseSemester() const;  
    void SetCourseNumber(const string &rhs); 
    void SetCourseTitle(const string &rhs); 
    void SetCourseAttribute(const string &rhs); 
    void SetTotalClassHours(const size_t rhs); 
    void SetTeachingHours(const size_t rhs); 
    void SetExperimentHours(const size_t rhs); 
    void SetCredit(const size_t rhs); 
    void SetCourseSemester(const size_t rhs); 

    




}; 


#endif