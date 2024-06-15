#include "../../include/File.h"
#include <sstream>

File::File(std::string path) {
  in_.open(path,std::ios::in);
  out_.open(path, std::ios::in);
}

File::~File() {
  if(in_.is_open()) in_.close();
  if(out_.is_open()) out_.close();
}

void File::write(std::string data) {
  if(!out_.is_open())
    throw std::runtime_error("File not is not open.");
  out_ << data;
}

void File::writeLine(std::string line) {
  std::stringstream ss;
  ss << line << std::endl;
  write(ss.str());
}

bool File::readLine(std::string &line) {
  if(!in_.is_open())
    throw std::runtime_error("File not is not open.");
  if(std::getline(in_, line))
    return true;   
  else 
    return false;
}
