#include "../../../include/TopicDAO.h"
#include "../../../include/Topic.h"
#include <sstream>
#include <string>

std::string TopicDAO::getData(Topic obj, char s)  {
  std::stringstream ss;
  ss << obj.getId() << s << obj.getName();
  return ss.str();
}

TopicDAO::TopicDAO(std::string path) : DAO(path) {}

Topic TopicDAO::getObject(Queue<std::string> data) {
  Topic t;
  t.setId(std::stoi(data.denqueue()));
  t.setName(data.denqueue());
  return t;
}
