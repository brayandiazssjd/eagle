#include "../../include/Student.h"

Student::Student(){
}

Student::Student(std::string name, long id ,std::vector<Grade*> grades)
{
    this->name = name;
    this->id = id;
    this->grades = grades;
    //this->course = course;
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

std::vector<Grade*> getGrades()
{
    return grades;
}

void Student::setGrades(std::vector<Grade*> grades) {
    this->grades = grades;
}

/*
std::string getCourse(){
	return course;
}

void setCourse(const std::string& course){
	this->course = course;
}
*/
Student::~Student()
{
}
