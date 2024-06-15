#ifndef DAO_H
#define DAO_H

#include "File.h"
#include "Queue.h"
#include <sstream>
#include <string>

template <typename T>
class DAO {
public:
  DAO(std::string path);
  ~DAO();

  Queue<T> getAll();
  void save(Queue<T> set);
  virtual T getObject(Queue<std::string> data) = 0;
  std::string getPath();
  void setPath(std::string path);
  virtual std::string getData(T obj, char s) = 0;

private:
  std::string path_;

  Queue<std::string> split(std::string line, char s);
};

template <typename T>
DAO<T>::DAO(std::string path) : path_(path) {}

template <typename T>
DAO<T>::~DAO() {}

template <typename T>
void DAO<T>::setPath(std::string path) {
  path_ = path;
}

template <typename T>
std::string DAO<T>::getPath() {
  return path_;
}

template <typename T>
Queue<std::string> DAO<T>::split(std::string line, char s) {
  std::stringstream ss(line);
  std::string aux;
  Queue<std::string> q;
  while(std::getline(ss, aux, s))
    q.enqueue(aux);
  return q;
} 

template <typename T>
void DAO<T>::save(Queue<T> l) {
  std::stringstream ss;
  int k = l.length();
  for(int i = 0; i < k; i++) {
    T obj = l.denqueue();
    ss << getData(obj, ',')<<std::endl;
  }
  File file(getPath());
  file.write(ss.str());
}

template<typename T>
Queue<T> DAO<T>::getAll() {
  File file(path_); 
  std::string line;
  Queue<T> q;
  while(file.readLine(line))
    q.enqueue(getObject(split(line, ','))); 
  return q;
}

#endif // !DAO_H


