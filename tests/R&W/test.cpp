#include "Product.h"
//#include "List.h"
#include "Queue.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>



Queue<Product> getAll() {
  Queue<Product> l;
  std::string line;
  std::ifstream input("data.txt");

  if(!input.is_open())
    throw std::runtime_error("File not found");

  while(std::getline(input, line)) {
    Queue<std::string> data = getData(line, ',');
    Product p;
    p.setId(std::stoi(data.denqueue()));
    p.setName(data.denqueue());
    p.setPrice(std::stod(data.denqueue()));
    l.enqueue(p);
  }
  input.close();
  return l;
} 
/*Queue<std::string> getData(std::string stream, char cut) {
  std::stringstream ss(stream);
  Queue<std::string> q;
  std::string temp;
  while(std::getline(ss, temp, cut))
    q.enqueue(temp);
  return q;
}*/
void save(Queue<Product> l) {
  std::ofstream output("data.txt");
  if(!output.is_open())
    throw std::runtime_error("File not is not open.");
  for(int i = 0; i < l.length(); i++) {
    Product p = l.denqueue();
    output<<p.getId()<<","<<p.getName()<<","<<p.getPrice()<<std::endl;
  }
  output.close();
}

int main (int argc, char *argv[]) {
  Queue<Product> q = getAll();
  std::cout<<q.length()<<std::endl;
  //q.enqueue(*(new Product(4, "chair", 599)));
  std::cout<<q.length()<<std::endl;
  //save(q);
  int k = q.length();
  for (int i = 0; i < k; i++) {
    std::cout<<q.denqueue().toString()<<" "<<i<<" "<<q.length()<<std::endl;
  }
  std::cout<<q.length();
  return 0;
} 
