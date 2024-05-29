#ifndef TOPICDAO_H
#define TOPICDAO_H

#include "Topic.h"
#include "Queue.h"
#include <string>


class TopicDAO {
public:
  Queue<Topic> getAll();
  void save(Queue<Topic> q);
private:
  std::string path;
};

#endif // !TOPICDAO_H
