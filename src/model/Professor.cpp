#include "../../include/Professor.h" 

Professor::Professor() {}

std::string Professor::getNames() { 
  return names; 
}

void Professor::setNames(std::string names) { 
  this->names = names; 
}

std::string Professor::getLastNames() { 
  return lastNames; 
}

void Professor::setLastNames(std::string lastNames) { 
  this->lastNames = lastNames; 
}

int Professor::getId() { 
  return id; 
}

void Professor::setId(int id) { 
  this->id = id; 
}

Professor::~Professor() {}

std::string Professor::toString() {
    return "ID: " + std::to_string(id) + ", Nombres: " + names + ", Apellidos: " + lastNames;
}