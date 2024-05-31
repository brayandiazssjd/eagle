#include "../../include/Grade.h"

Grade::Grade(){
}

Grade::Grade(std::string name, float percentage, Point *points){
    this->name = name;
    this->percentage = percentage;
    this->points = points;
}

std::string Grade::getName(){
    return name;
}

float Grade::getPercentage(){
    return percentage;
}

Point getPoint(){
	return point;
}

Grade::~Grade(){
}
