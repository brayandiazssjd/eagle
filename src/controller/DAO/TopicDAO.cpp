#include "../../../include/TopicDAO.h"
#include "../../../include/Topic.h"
#include "../../../include/File.h"
#include <sstream>
#include <string>
void TopicDAO::save(Queue<Topic> q) {
  while (!q.isEmpty()) {
  }
}

void TopicDAO::setPath(std::string path) {
  filePath = path;
}

TopicDAO::TopicDAO() {};

TopicDAO::TopicDAO(std::string _filepath) {
  filePath = _filepath;
}

//void TopicDAO::save
Queue<std::string> getData(std::string line, char s) {
  std::stringstream ss(line);
  std::string aux;
  Queue<std::string> q;
  while(std::getline(ss, aux, s))
    q.enqueue(aux);
  return q;
} 

Queue<Topic> TopicDAO::getAll() {
  File f(path_);

  Queue<Topic> q = f.getAll();
  int k = q.length();
  for(int i = 0; i < k; i++) {

  }
  std::string line;
  

    
  }
  infile.close();
  return q;
}
