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
    void setName(const std::string& name);
void setId(long id);
void setGrades(Grade* grades);
    ~Student();
};

#endif // STUDENT_H