#ifndef DAO_H
#define DAO_H

#include "Queue.h"
#include <sstream>
#include <string>

template <typename T>
class DAO {
public:
  DAO(std::string path);
  ~DAO();
  virtual Queue<T> getAll() = 0;
  virtual void save(Queue<T> set) = 0;
  std::string getPath();
  void setPath(std::string path);
protected:
  Queue<std::string> getData(std::string line, char s);
private:
  std::string path_;
};

template <typename T>
DAO<T>::DAO(std::string path) : path_(path) {}

template <typename T>
void DAO<T>::setPath(std::string path) {
  path_ = path;
}

template <typename T>
std::string DAO<T>::getPath() {
  return path_;
}

template <typename T>
Queue<std::string> DAO<T>::getData(std::string line, char s) {
  std::stringstream ss(line);
  std::string aux;
  Queue<std::string> q;
  while(std::getline(ss, aux, s))
    q.enqueue(aux);
  return q;
} 

#endif // !DAO_H


