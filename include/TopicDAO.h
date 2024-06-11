#ifndef TOPICDAO_H
#define TOPICDAO_H

#include "Topic.h"
#include "Queue.h"
#include "DAO.h"
#include <string>


class TopicDAO : public DAO<Topic>{
public:
  Queue<Topic> getAll();
  void save(Queue<Topic> q);
  TopicDAO(std::string filePath);
  TopicDAO();
  void setPath(std::string filePath);
private:
  std::string filePath;
};

#endif // !TOPICDAO_H
