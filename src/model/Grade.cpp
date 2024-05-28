#include "Grade.h"

Grade::Grade(){
}

Grade::Grade(std::string name, int percentage, Point *points){
    this->name = name;
    this->percentage = percentage;
    this->points = points;
}

std::string Grade::getName(){
    return name;
}

int Grade::getPercentage(){
    return percentage;
}

Grade::~Grade(){
}