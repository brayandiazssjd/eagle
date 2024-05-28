#include <string>

class Point {
private:
  std::string topic;
  int percentage;

public:
  Point();
  Point(std::string topic, int percentage);
  std::string getTopic();
  int getPercentage();
  ~Point();
};

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
