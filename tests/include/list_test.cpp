#include "../../include/List.h"
#include <iostream>

template <typename T>
void print(List<T> l) {
	for (int i = 0; i < l.length(); ++i) {
		std::cout<<" "<<l.get(i);
	}
}
int main(int argc, char const *argv[]) {
	List<int> l;
	int input=0;
	std::cin>>input;
	l.add(input);
	print(l);
	while(input != 0) {
		std::cin>>input;
		l.add(input);
		print(l);
		std::cout<<std::endl;
	}

	return 0;
}
