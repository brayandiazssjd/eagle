#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Grade.h"

class Student
{
private:
    std::string name;
    long id;
    Grade *grades;
public:
    Student();
    Student(std::string name, long id, Grade *grades);
    std::string getName();
    long getId();
    Grade *getGrades();
    ~Student();
};

#endif // STUDENT_H