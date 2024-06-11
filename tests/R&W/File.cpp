#include "File.h"
#include <fstream>
#include <string>

//File::File(std::string path, int line) : path_(path), line_(line) {}

File::File(std::string path) : path_(path), line_(0) {}

File::File() : path_(""), line_(0) {}

File::~File() {}

void File::writeAll(Queue<std::string> s) {
  std::ofstream output(path_);
  if(!output.is_open())
    throw std::runtime_error("File not is not open.");
  int k = s.length();
  for(int i = 0; i < k; i++) {
    output<<s.denqueue()<<std::endl;
  }
  output.close();
}

void File::setPath(std::string path) {
  path_ = path;
}

Queue<std::string> File::readAll() {
  Queue<std::string> l;
  std::string line;
  std::string path;
  std::ifstream input(path_);

  if(!input.is_open())
    throw std::runtime_error("File not found");

  while(std::getline(input, line)) {
    l.enqueue(line);
  }
  input.close();
  return l;
}



