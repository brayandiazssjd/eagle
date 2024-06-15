#include "../include/Topic.h"
#include "../include/TopicDAO.h"
#include <iostream> 

int main (int argc, char *argv[]) {
  TopicDAO dao("test.txt");
  Queue<Topic> q = dao.getAll();
  //int k = q.length();
  q.enqueue(*(new Topic("punteros", 6)));
  dao.save(q);
//  for(int i = 0; i < k; i++)
//    std::cout<<q.denqueue().toString();
  std::cout<<"good";
	return 0;
}
