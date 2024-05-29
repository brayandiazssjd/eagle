#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>

class Professor {
private:
  std::string names, lastNames;
  long id;
  int classesNumber;

public:
  Professor();
  Professor(Professor &&) = default;
  Professor(const Professor &) = default;
  Professor &operator=(Professor &&) = default;
  Professor &operator=(const Professor &) = default;
  ~Professor();

  std::string getNames();
  void setNames(std::string names);
  std::string getLastNames();
  void setLastNames(std::string lastNames);
  int getId();
  void setId(int id);
};

#endif // PROFESSOR_H