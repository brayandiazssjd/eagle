#ifndef AVLTREE_H
#define AVLTREE_H

#include "Sortable.h"

template <typename T>
class AVLTree {
public:
  void add(Sortable<T> e);
  void get(T id);
  void remove(T id);
  void update(Sortable<T> e);

private:

};

#endif
