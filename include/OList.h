#ifndef OLIST_H
#define OLIST_H

#include "Node.h"

template <typename T>
class OList {
private:
	int size;
  Node<T> *head;
  Node<T> *tail;
  
  bool validIndex(int index);

public:
	OList(int _size);
  OList();
	~OList();
	void add(T e);
	void remove(int index);
	T get(int index);
	int length();
	bool isEmpty();
};

template <typename T>
OList<T>::OList(int _size) {
  size = _size;
  head = new Node<T>();
  tail = new Node<T>();
  head->next = tail;
}

template <typename T>
OList<T>::OList() {
  OList(0); 
}

template <typename T>
OList<T>::~OList() {
  Node<T> *aux = head;
  for(int i = 0; i < size; i++) {
    head = head->next;
    delete aux;
    aux = head;
  }
  delete head;
  delete tail;
}

template <typename T>
int OList<T>::length() {
  return size;
}

template <typename T> 
void OList<T>::add(T e) {
  Node<T> *aux = head->next;
  for(int i = 0; i < size; i++) {
    if(e > aux->value)
      aux = aux->next;
    else
      break;
  }
  Node<T> *temp = new Node<T>();
  temp->value = aux->value;
  temp->next = aux->next;
  aux->value = e;
  aux->next = temp;
}

template <typename T>
bool OList<T>::validIndex(int index) {
  return 0 < index && index < size;
}

template <typename T>
T OList<T>::get(int index) {
  Node<T> *aux = head->next;
  for(int i = 0; i < index; i++) {
    aux = aux->next;
  }
  return aux->value;
}

#endif
