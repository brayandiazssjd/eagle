#include "../../include/Topic.h"
#include <sstream>

Topic::Topic(){
}

Topic::Topic(std::string name, int id){
    this->name = name;
    this->id = id;
}

std::string Topic::getName(){
    return name;
}

int Topic::getId(){
    return id;
}

void Topic::setId(int _id) {
    id = _id;
}

void Topic::setName(std::string _name) {
    name = _name;
}

std::string Topic::toString() {
  std::stringstream ss;
  ss<<"Topic (id="<<id<<", name="<<name<<")";
  return ss.str();
}

Topic::~Topic(){
}
