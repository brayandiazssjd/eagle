#include "Stack.h"
#include <iostream>

void fill(Stack<int> *s, int start, int multiplier, int times) {
	int aux = start;
	for (int i = start; i < times; i++) {
		aux += multiplier * i;
		s->push(aux);
	}
}

void transport(Stack<int> *origin, Stack<int> *destination) {
	while (!origin->isEmpty()) {	
		destination->push(origin->pop());
	}
}

template <typename T>
void print(Stack<T> *s) {
	while (!s->isEmpty()) {
		std::cout<<s->pop()<<" ";
	}
}


int main (int argc, char *argv[]) {
	Stack<int> *up = new Stack<int>();
	up->push(1);
	up->push(2);
	up->push(3);
	print(up);
	delete up;
	return 0;
}
