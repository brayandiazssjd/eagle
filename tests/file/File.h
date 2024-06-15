#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>

class File {
public:
  File();
  ~File();
  File(std::string path);
  void write(std::string data);
  bool readLine(std::string &line);
  void writeLine(std::string line);

private:
  std::ifstream in_;
  std::ofstream out_;
};

#endif
