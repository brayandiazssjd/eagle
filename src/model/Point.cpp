#include "../../include/Point.h"

Point::Point() {
}

Point::Point(std::string topic, int percentage) {
  this->topic = topic;
  this->percentage = percentage;
}

std::string Point::getTopic() {
  return topic;
}

int Point::getPercentage() {
  return percentage;
}

Point::~Point() {
}