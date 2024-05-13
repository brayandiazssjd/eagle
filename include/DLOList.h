#ifndef LIST_H
#define LIST_H

#include "DLNode.h"
#include <stdexcept>

template <typename T> class DLOList {
private:
  DLNode<T> *head, *tail;
  int size;

public:
  DLOList() {
    size = 0;
    tail = new DLNode<T>();
    head = new DLNode<T>();
    head->next = tail;
    tail->previous = head;
  }

  ~DLOList() {
    DLNode<T> *aux;
    for (int i = 0; i < size; i++) {
      aux = head->next;
      head->next = aux->next;
      delete aux;
    }
    delete tail;
    delete head;
  }  

  bool validPosition(int p) {
    return -1 < p && p < size;
  }

  bool isEmpty() {
    return size == 0;
  }

  /*
   * Agrega el elemento de manera ordena.
    */
  void add(T e) {
    DLNode<T> *aux = head->next;
    int index = 0;    
    while (index < size && e < aux->value) { 
    	aux = aux->next;
    	index++;
    }
    DLNode<T> *temp = new DLNode<T>(e);
    temp->next = aux;
    temp->previous = aux->previous;
    aux->previous->next = temp;
    aux->previous = temp;    
    size++;
  }

  /*
   * Retorna el elemento en la posición 'index'.
   */
  T get(int index) {
    if (!validPosition(index))
      throw std::out_of_range("Index out of range");
    DLNode<T> *temp;
    if (index > -1) {
      temp = head->next;
      for (int i = 0; i < index; i++)
        temp = temp->next;
    } else {
      temp = tail->previous;
      for (int i = index; i < -1; i--)
        temp = temp->previous;
    }   
    return temp->value;
  }

  /*
   * Elimina el elemento 'e'.
   */
  void remove(T e) {
    if (isEmpty()) 
      throw std::out_of_range("Index out of range");
    
    int index = 0;
    DLNode<T> *aux = head->next;
    while (index < size && e < aux->value) { 
      aux = aux->next;
      index++;
    }
    aux->previous->next = aux->next;
    aux->next->previous = aux->previous;
    delete aux;
    size--;
  }

  // TODO
  // Elimina el elemento en la pasición 'index'.
  void remove(int index);

  int length() { return size; }
  
	/*
  std::string toString() {
      if (size == 0) {
    return "List []";
  }

    std::string str = "List [";
    DLNode<T> *aux = head->next;
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
    DLNode<T> *t = head->next;
    for (int i = 0; i < size; i++) {
      std::cout << t->value;
      t = t->next;
    }
  }*/
};

#endif
