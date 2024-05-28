#ifndef POINT_H
#define POINT_H

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

#endif // POINT_H