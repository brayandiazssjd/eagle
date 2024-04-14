#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {
	T value;
	Node<T> *next;
//	Node() {}
//	Node(T v) : value(v) {}
//	Node(Node<T> *n, T v) : next(n), value(v) {}
};

#endif
