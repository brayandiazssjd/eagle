#ifndef TOPIC_H
#define TOPIC_H

#include <string>

class Topic {
public:
  Topic();
  Topic(std::string name, int id);
  std::string getName();
  int getId();
  void setName(std::string _name);
  void setId(int _id);
  ~Topic();
  std::string toString();

private:
  std::string name;
  int id;
};

#endif // TOPIC_H
