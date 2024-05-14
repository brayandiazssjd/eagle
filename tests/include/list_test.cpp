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
	int input;
	std::cin>>input;
	l.add(input);
	print(l);
	while(input != 0) {
		std::cin>>input;
		l.add(input);
		print(l);
	}

	return 0;
}