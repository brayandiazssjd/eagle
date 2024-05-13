#ifndef OLIST_H
#define OLIST_H

#include "Node.h"

template <typename T>
class OList {
private:
	int size;
public:
	OList() {
		size = 0;
	}
	~OList();
	void add() {}
	void remove(int index) {};
	T get();
	int length() {
		return size;
	}
	bool isEmpty() { return size == 0; }
};

#endif