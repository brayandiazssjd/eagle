#include "../../include/Student.h"

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

void Student::setName(const std::string& name) {
    this->name = name;
}

long Student::getId()
{
    return id;
}

void Student::setId(long id) {
    this->id = id;
}

Grade *Student::getGrades()
{
    return grades;
}

void Student::setGrades(Grade* grades) {
    this->grades = grades;
}

Student::~Student()
{
}