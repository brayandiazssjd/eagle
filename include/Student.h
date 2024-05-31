#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Grade.h"

class Student
{
private:
    std::string name;
    long id;
    std::vector<Grade*> grades;
    std::string group;

public:
    Student();
    Student(std::string name, long id, std::vector<Grade*> grades);
    Student(std::string name, long id, std::vector<Grade*> grades, std::string group);

    std::string getName();
    long getId();
    std::vector<Grade*> getGrades();
    std::string getGroup();
    void setName(const std::string& name);
    void setId(long id);
    void setGrades(std::vector<Grade*> grades);
    void setGroup(const std::string& group);
    ~Student();
};

#endif // STUDENT_H

