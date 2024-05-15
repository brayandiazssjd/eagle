#include "List.h"
#include "Stack.h"

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
	List<int> l;
	Stack<int> *s = new Stack<int>();
	s->push(3);
	s->push(2);
	s->push(1);
	print(s);

//	l.add(1);
//	l.add(2);
//	l.add(3);
//	print(l);
	return 0;
}
