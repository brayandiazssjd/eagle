#ifndef FILE_H
#define FILE_H

#include "Queue.h"
#include <string>

class File {
public:
  File();
  ~File();
  //File(std::string path, int line);
  File(std::string path);
  //std::string readLine(int line);
  //std::string readLine();
  Queue<std::string> readAll();
  //write(std::string line);
  void writeAll(Queue<std::string> s);
  //write(std::string, line);
  void setPath(std::string path);

private:
  int line_;
  std::string path_;
};

#endif
