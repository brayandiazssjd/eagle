#include "File.h"
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
  File file("data.txt");

//  file.writeLine("1,a,0.88");
//  file.writeLine("2,b,0.58");
//  file.writeLine("3,c,0.39");

  std::string d;
  while(file.readLine(d)) {
    std::cout<<d<<std::endl;
  }
  std::cout<<"good"; 
  return 0;
}
