#ifndef DLNODE_H
#define DLNODE_H

template<typename T>
struct Node {
	T value;
	Node<T> *next, *previous;
	Node() {}
	Node(T v) : value(v) {}
	Node(Node<T> *n, T v) : next(n), value(v) {}
  Node(Node<T> *n, Node<T> *p, T v) : next(n), previous(p), value(v) {}
};

#endif
