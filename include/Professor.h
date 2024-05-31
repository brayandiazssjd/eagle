#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>

class Professor {
private:
  std::string names, lastNames;
  int id;
  int classesNumber;

public:
  Professor();
  ~Professor();

  std::string getNames();
  void setNames(std::string names);
  std::string getLastNames();
  void setLastNames(std::string lastNames);
  int getId();
  void setId(int id);
  std::string toString();
  int getClassesNumber();
  void setClassesNumber(int classesNumber);
  
};

#endif // PROFESSOR_H
