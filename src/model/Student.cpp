#include "Student.h"

Student::Student(){
}

Student::Student(std::string name, long id, Grade *grades)
{
    this->name = name;
    this->id = id;
    this->grades = grades;
}

std::string Student::getName()
{
    return name;
}

long Student::getId()
{
    return id;
}

Grade *Student::getGrades()
{
    return grades;
}

Student::~Student()
{
}