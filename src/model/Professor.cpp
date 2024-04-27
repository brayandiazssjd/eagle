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

  std::string getNames() { return names; }

  void setNames(std::string names) { this->names = names; }

  std::string getLastNames() { return lastNames; }

  void setLastNames(std::string lastNames) { this->lastNames = lastNames; }

  int getId() { return id; }

  void setId(int id) { this->id = id; }
};

Professor ::Professor() {}

Professor ::~Professor() {}
