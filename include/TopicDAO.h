#ifndef TOPICDAO_H
#define TOPICDAO_H

#include "Topic.h"
#include "Queue.h"
#include "DAO.h"
#include <string>


class TopicDAO : public DAO<Topic> {
public:
  TopicDAO(std::string path);
  std::string getData(Topic obj, char s) override;
  Topic getObject(Queue<std::string> data) override;
};

#endif // !TOPICDAO_H
