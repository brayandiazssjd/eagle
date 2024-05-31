#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Grade.h"

class Student
{
private:
    std::string name;
    long id;
    //std::string course;
    std::vector<Grade*> grades;
public:
    Student();
    Student(std::string name, long id, std::vector<Grade*> grades);
    std::string getName();
    long getId();
    std::vector<Grade*> getGrades();
    //std::string getCourse();
    void setName(const std::string& name);
	void setId(long id);
	void setGrades(std::vector<Grade*> grades);
	//void setCourse(const std::string& course);
    ~Student();
};

#endif // STUDENT_H
