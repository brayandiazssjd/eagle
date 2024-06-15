#ifndef AVLNODE_H
#define AVLNODE_H

template <typename T>
struct AVLNode {
  T value;
  int bf; // balance factor
  AVLNode<T> *l, *r, *p;
};

#endif // !AVLNODE_H

