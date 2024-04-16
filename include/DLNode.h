#ifndef DLNODE_H
#define DLNODE_H

template<typename T>
struct DLNode {
	T value;
	DLNode<T> *next, *previous;
	DLNode() {}
	DLNode(T v) : value(v) {}
	DLNode(DLNode<T> *n, T v) : next(n), value(v) {}
  DLNode(DLNode<T> *n, DLNode<T> *p, T v) : next(n), previous(p), value(v) {}
};

#endif
