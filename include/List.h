#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <cstddef>
#include <stdexcept>

template <typename T> class List {
private:
  Node<T> *head, *tail;
  int size;

public:
  List() {
    head = new Node<T>();
    tail = new Node<T>();
    head->next = tail;
    size = 0;
  }

  ~List() {
    Node<T> *aux;
    for (int i = 0; i < size; i++) {
      aux = head->next;
      head->next = aux->next;
      delete aux;
    }
    delete tail;
    delete head;
  }  

  bool validIndex(int index) { 
    return (-1 < index && index < size); 
  }

  void add(T e) {
    tail->value = e;
    tail->next = new Node<T>();
    tail = tail->next;
    size++;
  }

  void addFirst(T e) {
    Node<T> *temp = new Node<T>();
    temp->next = head->next;
    temp->value = e;
    head->next = temp;
    size++;
  }

  void add(T e, int index) {
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

  void removeIndex(int index) {
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


  // Removes the element that matches with 'e'.
  void remove(T e) {
    if (isEmpty())
      throw std::out_of_range("Index out of bounds");
    Node<T> *aux = head;
    for (int i = 0; i < size; ++i) {
      aux = aux->next;
			if(aux->value == e) {
        Node<T> *temp = aux->next;
        aux->value = temp->value;
        aux->next = temp->next;
        delete temp;
        return;
			}
    }
  }

  T get(int index) {
    if (!validIndex(index))
      throw std::out_of_range("Index out of bounds");
    Node<T> *aux = head->next;
    for (int i = 0; i < index; i++) {
      aux = aux->next;
    }
    return aux->value;
  }

  bool isEmpty() { return size == 0; }

  int length() { return size; }
};

#endif
