#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>
class List {
public:
  List();
  ~List();

  void add(T e);
  void addFirst(T e);
  void add(T e, int index);
  void removeIndex(int index);
  void remove(T e);
  T get(int index);
  bool isEmpty();
  int length();
  void toString();
  T* toArray();

private:
  Node<T> *head, *tail;
  int size;

  bool validIndex(int index);
};

template <typename T>
void List<T>::add(T e) {
  tail->value = e;
  tail->next = new Node<T>();
  tail = tail->next;
  size++;
}

template <typename T>
void List<T>::addFirst(T e) {
  Node<T> *temp = new Node<T>();
  temp->next = head->next;
  temp->value = e;
  head->next = temp;
  size++;
}

template <typename T> 
List<T>::~List() {
  Node<T> *aux;
  for (int i = 0; i < size; i++) {
    aux = head->next;
    head->next = aux->next;
    delete aux;
  }
  delete tail;
  delete head;
}

template <typename T>
T* List<T>::toArray() {
  T *array = new T[size];
  Node<T> *aux = head;
  for(int i = 0; i < size; i++) {
    aux = aux->next;
    array[i] = aux;
  }
  return array;
}

template <typename T>
bool List<T>::validIndex(int index) {
  return (-1 < index && index < size);
}
template <typename T>
void List<T>::add(T e, int index) {
  if (!validIndex(index))
    throw std::out_of_range("Index out of bounds");
  Node<T> *aux = head;
  for (int i = 0; i < size; i++) {
    aux = aux->next;
  }
  Node<T> *temp = new Node<T>();
  temp->value = e;
  temp->next = aux->next;
  aux->next = temp;
  size++;
}

template <typename T>
void List<T>::removeIndex(int index) {
  if (!validIndex(index))
    throw std::out_of_range("Index out of bounds");
  Node<T> *aux = head;
  for (int i = 0; i < index; ++i) {
    aux = aux->next;
  }
  Node<T> *temp = aux->next;
  aux->next = temp->next;
  delete temp;
}

template <typename T>
void List<T>::remove(T e) {
  if (isEmpty())
    throw std::out_of_range("Index out of bounds");
  Node<T> *aux = head;
  for (int i = 0; i < size; ++i) {
    aux = aux->next;
    if (aux->value == e) {
      Node<T> *temp = aux->next;
      aux->value = temp->value;
      aux->next = temp->next;
      delete temp;
      return;
    }
  }
}

template <typename T>
bool List<T>::isEmpty() { return size == 0; }

template <typename T>
T List<T>::get(int index) {
  if (!validIndex(index))
    throw std::out_of_range("Index out of bounds");
  Node<T> *aux = head->next;
  for (int i = 0; i < index; i++) {
    aux = aux->next;
  }
  return aux->value;
}

template <typename T>
int List<T>::length() { return size; }

template <typename T>
void List<T>::toString() {
  Node<T> *aux = head->next;
  for (int i = 0; i < length(); i++) {
    std::cout << " " << aux->value;
    aux = aux->next;
  }
}

template <typename T>
List<T>::List() {
  head = new Node<T>();
  tail = new Node<T>();
  head->next = tail;
  size = 0;
}

#endif
