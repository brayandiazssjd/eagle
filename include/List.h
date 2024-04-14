#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <cstddef>
#include <stdexcept>

template <typename T>
class List {
  Node<T> *head, *tail;
  int size;

public:
  List() {
    head = new Node<T>();
		tail = new Node<T>();
		head->next = tail;
		head->value = 0;
		tail->next = tail;
		tail->value = 0;
    size = 0;
  }

//	~List() {
//		Node<T> *aux;
//		for (int i = 0; i < size+2; i++) {
//			aux = head->next;
//			delete head;
//			head = aux;
//		}
//		delete aux;
//		delete head;
//	}

  bool validIndex(int index) {
  	return -1 < index && index < size;
  }

  void add(T e) {
    Node<T> *aux = head;
    for (int i = 0; i < size; ++i) {
    	aux = aux->next;
    }
 		Node<T> *temp = new Node<T>();
		temp->value = e;
		temp->next = tail;
		aux->next = temp;

 		delete aux;    
    size++;
    
  }

	void add(T e, int index) {
		if(!validIndex(index))
			throw std::out_of_range("Index out of bounds");
		Node<T> *aux = head;
		for (int i = 0; i < size; i++) {
			aux = aux->next;
		}
		Node<T> *temp = new Node<T>();
		temp->value = e;
		temp->next = aux->next;
		aux->next = temp;
		delete aux;
		delete temp;
		size++;
	}

  void addFirst(T e) {
    Node<T> *temp = new Node<T>();
    temp->next = head->next;
    temp->value = e;
    head->next = temp;
    delete temp;
    size++;
  }

  void remove(int index) {
  	if(!validIndex())
  		throw std::out_of_range("Index out of bounds");
  	Node<T> *aux = head;
  	for (int i = 0; i < index; ++i) {
  		aux = aux->next;
  	}
  	Node<T> temp = aux->next->next;
		delete aux->next;
		aux->next = temp;
		delete temp;
		delete aux;
	}

  T get(int index) {
  	if(!validIndex(index))
  		throw std::out_of_range("Index out of bounds");
		Node<T> *aux = head->next;
    for (int i = 0; i < index; i++) {
    	aux = aux->next;
    }
    T e = aux->value;
    delete aux;
    return e;
  }

  bool isEmpty() { 
		return size == 0;
	}

	int length() {
		return size;
	}
};

#endif
