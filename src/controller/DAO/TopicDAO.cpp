#include "../../../include/TopicDAO.h"
#include "../../../include/Topic.h"
#include <fstream>
#include <iostream>
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

Queue<Topic> TopicDAO::getAll() {
  Queue<Topic> q;
  std::ifstream infile("../../../data/topics.txt");
  if (!infile.is_open()) {
    std::cerr << "Error opening file for reading: topics.txt" << std::endl;
    return q; // Return empty vector on error
  }
  std::string line;
  while (std::getline(infile, line)) {
    std::stringstream ss(line);
    std::string id, name;

    std::getline(ss, id, ','); 
    std::getline(ss, name, ',');
    q.enqueue(Topic(name, std::stoi(id))); // Create and add Topic object to vector
  }
  infile.close();
  return q;
}
