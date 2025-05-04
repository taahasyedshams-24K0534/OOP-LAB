//COURSE.H
#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<string>
using namespace std

class Course
{
protected:
    string courseCode
    int credits
public:
    Course(string code,int c):courseCode(code),credits(c){}
    virtual void calculateGrade()=0
    virtual void displayInfo()=0
    virtual~Course(){}
}
#endif

//LECTURECOURSE.H
#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H
#include"Course.h"

class LectureCourse:public Course
{
public:
    LectureCourse(string code,int c):Course(code,c){}
    void calculateGrade()
    void displayInfo()
}
#endif

//LECTURECOURSE.CPP
#include"LectureCourse.h"

void LectureCourse::calculateGrade()
{
    cout<<"Calculating grade for lecture course:"<<courseCode<<endl
}

void LectureCourse::displayInfo()
{
    cout<<"Lecture Course:"<<courseCode<<endl
    cout<<"Credits:"<<credits<<endl
}
//LABCOURSE.H
#ifndef LABCOURSE_H
#define LABCOURSE_H
#include"Course.h"

class LabCourse:public Course
{
public:
    LabCourse(string code,int c):Course(code,c){}
    void calculateGrade()
    void displayInfo()
}
#endif

//LABCOURSE.CPP
#include"LabCourse.h"

void LabCourse::calculateGrade()
{
    cout<<"Calculating grade for lab course:"<<courseCode<<endl
}

void LabCourse::displayInfo()
{
    cout<<"Lab Course:"<<courseCode<<endl
    cout<<"Credits:"<<credits<<endl
}


//MAIN
#include"LectureCourse.h"
#include"LabCourse.h"

int main()
{
    Course*course1=new LectureCourse("CS101",3)
    Course*course2=new LabCourse("CS101L",1)
    course1->displayInfo()
    course1->calculateGrade()
    cout<<endl
    course2->displayInfo()
    course2->calculateGrade()
    delete course1
    delete course2
    return 0
}

