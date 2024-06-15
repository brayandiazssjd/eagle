#include "Product.h"
#include "Queue.h"
#include "File.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

Queue<std::string> getData(std::string line, char s) {
  std::stringstream ss(line);
  std::string aux;
  Queue<std::string> q;
  while(std::getline(ss, aux, s))
    q.enqueue(aux);
  return q;
} 

Product getObject(Queue<std::string> data) {
  Product p;
  p.setId(std::stoi(data.denqueue()));
  p.setName(data.denqueue());
  p.setPrice(std::stod(data.denqueue()));
  return p;
}

Queue<Product> getAll() {
  Queue<Product> l;
  File f("data.txt");
  std::string line;
  while(f.readLine(line)) 
    l.enqueue(getObject(getData(line, ',')));

  return l;
}

void save(Queue<Product> l) {
  std::ofstream output("data.txt");
  if(!output.is_open())
    throw std::runtime_error("File not is not open.");
  int k = l.length();
  for(int i = 0; i < k; i++) {
    Product p = l.denqueue();
    output<<p.getId()<<","<<p.getName()<<","<<p.getPrice()<<std::endl;
  }
  output.close();
}

int main (int argc, char *argv[]) {
  Queue<Product> q = getAll();
  for(int i = 0; i < 3; i++)
    std::cout<<q.denqueue().toString()<<std::endl;
  std::cout<<"goo";
  return 0;
} 
