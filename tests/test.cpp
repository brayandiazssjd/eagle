#include "../include/List.h"
#include "../include/Stack.h"
#include "../include/Topic.h"
#include "../include/TopicDAO.h"
#include <iostream>

template <typename T>
void print(List<T> l) {
	for (int i = 0; i < l.length(); i++) {
		std::cout<<l.get(i)<<" ";
	}
 }

template <typename T>
void print(Stack<T> *s) {
	while (!s->isEmpty()) {
		std::cout<<s->pop()<<" ";
	}
} 

int main (int argc, char *argv[]) {
	Topic t;
	t.setId(10);
	t.setName("brayan");
	std::cout<<t.getName();

	TopicDAO dao;
	Queue<Topic> q = dao.getAll();
	std::cout<<q.denqueue().getName();
	return 0;
}
