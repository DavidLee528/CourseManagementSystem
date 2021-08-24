#include <iostream>
#include <string>

#include "../include/CMS.h"
#include "../include/course.h"

using std::string; 

CCourse::CCourse() {
    
}

string & CCourse::GetCourseNumber() {
    return courseNumber; 
}

string & CCourse::GetCourseTitle() {
    return courseTitle; 
}

string & CCourse::GetCourseAttribute() {
    return courseAttribute; 
}

size_t CCourse::GetTotalClassHours() {
    return totalClassHours; 
}
size_t CCourse::GetTeachingHours() {
    return teachingHours; 
}
size_t CCourse::GetExperimentHours() {
    return experimentHours; 
}

size_t CCourse::GetCredit() {
    return credit; 
}

int CCourse::GetCourseSemester() {
    return courseSemester; 
}