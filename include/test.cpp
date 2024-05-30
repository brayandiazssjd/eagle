#include "List.h"
#include "Stack.h"

#include <iostream>

template <typename T>
void print(List<T> l) {
	for (int i = 0; i < l.length()-1; i++) {
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
  
  int input = 0;
  std::cin>>input;
  while(input != 0) {
    l.add(input);
    for(int i = 0; i < l.length(); i++)
      std::cout<<" "<<l.get(i);
    std::cout<<std::endl;
    std::cin>>input;
  }
	return 0;
}
