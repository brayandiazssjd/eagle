#include "../../include/Point.h"

Point::Point() {
}

Point::Point(std::string topic, float percentage) {
  this->topic = topic;
  this->percentage = percentage;
}

std::string Point::getTopic() {
  return topic;
}

float Point::getPercentage() {
  return percentage;
}

Point::~Point() {
}
