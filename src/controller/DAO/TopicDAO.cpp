//#include "../../../include/TopicDAO.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
void TopicDAO::save(Queue<Topic> q) {
  while(!q.isEmpty()) {
    
  }
}

Queue<Topic> getAll() {
  Queue<Topic> q;
  std::ifstream infile(path);
    if (!infile.is_open()) {
        std::cerr << "Error opening file for reading: topics.txt" << std::endl;
        return q; // Return empty vector on error
    }

    std::string line;

      while (std::getline(infile, line)) {
        std::stringstream ss(line);
        int id;
        std::string name;

        // Extract id and name using comma as separator
        std::getline(ss, std::to_string(id), ','); // Read id as a string and convert to int
        std::getline(ss, name, ',');

        q.enqueque(Topic(id, name)); // Create and add Topic object to vector
    }

    infile.close();
 
  return q;
}
