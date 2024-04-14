#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T> class List {
private:
  node<T> *head, *tail;
  int size;

public:
  List() {
    size = 0;
    tail = new node<T>(NULL, NULL);
    head = new node<T>(tail, NULL, NULL);
    tail->prev = head;
  }
  bool validPosition(int p) {
    if (p > size - 1 || (-1) * p > size)
      return false;
    return true;
  }
  bool isEmpty() {
    if (size == 0)
      return true;
    return false;
  }
  /*
   * Agrega el elemento de manera ordena.
   */

  void add(T e) {
    node<T> *temp = head->next;
    node<T> *aux = new node<T>(e);
    int index = 0;    
    while (index < size && e < temp->value) { 
    	temp = temp->next;
    	index++;
    }
    aux->next = temp;
    aux->prev = temp->prev;
    temp->prev->next = aux;
    temp->prev = aux;    
    size++;
    delete temp;
		delete aux;
  }
  /*
   * Retorna el elemento en la posición 'pos'.
   */
  T get(int pos) {
    if(pos >= 1)
      pos--;
    if (!validPosition(pos))
      throw std::out_of_range("Index out of range");
    node<T> *temp;
    if (pos >= 0) {
      temp = head->next;
      for (int i = 0; i < pos; i++)
        temp = temp->next;
    } else {
      temp = tail->prev;
      for (int i = pos; i < -1; i++)
        temp = temp->prev;
    }
    T e = temp->value;
    delete temp;
    return e;
  }
  /*
   * Elimina el elemento de la posición indicada y retorna la información de
   * este.
   */
  T deletePos(T val) {
    if (head->next == tail) {
      throw std::out_of_range("Lista vacia");
    }
    node<T> *temp = head, *toDelete;
    T erased;
    for (int i = 1; i < size; i++) {
      if (temp->next->value < val) {
        temp = temp->next;
      } else {
        break;
      }
    }
    toDelete = temp->next;
    erased = toDelete->value;
    temp->next = temp->next->next;
    temp->next->previous = temp;
    delete toDelete;
    size--;
    return erased;
  }

  int length() { return size; }
  
	std::string toString() {
			if (size == 0) {
		return "List []";
	}

    std::string str = "List [";
    node<T> *aux = head->next;
    for (int i = 0; i < size - 1; i++) {
      str += std::to_string(aux->value) + ", "; // para números
      // str += aux->value + ", ";
      aux = aux->next;
    }
    // str += aux->value;
    str += std::to_string(aux->value); // para números
    delete aux;
    return str + "]";
  }

	void print() {
		node<T> *t = head->next;
		for (int i = 0; i < size; i++) {
			std::cout << t->value;
			t = t->next;
		}
	}
};

#endif
