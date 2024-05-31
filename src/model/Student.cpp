#include "../../include/Student.h"

Student::Student() {}

Student::Student(std::string name, long id, std::vector<Grade*> grades)
{
    this->name = name;
    this->id = id;
    this->grades = grades;
}

/*Student::Student(std::string name, long id, std::vector<Grade*> grades, std::string course)
{
    this->name = name;
    this->id = id;
    this->grades = grades;
    this->course = course;
}*/

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

std::vector<Grade*> Student::getGrades()
{
    return grades;
}

/*std::string Student::getGroup() {
    return group;
}*/

void Student::setGrades(std::vector<Grade*> grades) {
    this->grades = grades;
}

/*void Student::setGroup(const std::string& course) {
    this->course = course;
}*/

Student::~Student() {}

