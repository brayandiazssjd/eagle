#ifndef DLLIST_H
#define DLLIST_H

#include "DLNode.h"
#include <cstdlib>
#include <stdexcept>
#include <string>

template <typename T> class List {
private:
  DLNode<T> *head, *tail;
  int size;

public:
  List() {
    size = 0;
    head = new DLNode<T>();
    tail = new DLNode<T>();
		head->next = tail;
		head->previous = head;
		tail->next = tail;
		tail->previous = head;
  }

  bool validPosition(int p) {
    if (p > size - 1 || (-1) * p > size)
      return false;
    return true;
  }
  bool isEmpty() { return size == 0; }
  /*
   * Agrega al final.
   */
  void add(T e) {
		DLNode<T> *temp = new DLNode<T>();
		temp->next = tail;
		temp->value = e;
		temp->previous = tail->previous;
		tail->previous->next = temp;
    tail->previous = temp;
  	delete temp;
		size++;
	}

  /*
   * Agrega al inicio.
   */

  void addFirst(T e) {
		DLNode<T> *temp = new DLNode<T>();
		temp->value = e;
		temp->next = head->next;
    head->previous = new node<T>();
    head->previous->value = e;
    head->previous->previous = NULL;
    head->previous->next = head;
    head = head->previous;
  }
  size++;
}
/*
 * Agrega en una posición.
 */
void add(T e, int p) {
  if (p >= 1)
    p--;
  if (p == 0 || p <= (-1) * size)
    addFirst(e);
  else if (p >= size - 1 || p == -1)
    add(e);
  else {
    node<T> *temp;
    if (p >= 0) {
      temp = head;
      for (int i = 0; i < p - 1; i++)
        temp = temp->next;

    } else {
      temp = tail;
      for (int i = p; i < -1; i++)
        temp = temp->previous;
    }
    temp->next->previous = new node<T>();
    temp->next->previous->previous = temp;
    temp->next->previous->next = temp->next;
    temp->next = temp->next->previous;
    temp->next->value = e;
    size++;
    delete temp;
  }
}
/*
 * Retorna el elemento en la posición.
 */
T get(int pos) {
  if (pos >= 1)
    pos--;
  if (!validPosition(pos))
    throw std::out_of_range("Index out of range");
  node<T> *temp;
  if (pos >= 0) {
    temp = head;
    for (int i = 0; i < pos; i++)
      temp = temp->next;
  } else {
    temp = tail;
    for (int i = pos; i < -1; i++)
      temp = temp->previous;
  }
  delete temp;
  return temp->value;
}

T eliminar_pos(int pos) {
  if ((pos * -1) > size) {
    return 0;
  } else if (pos == 1) {
    node<T> *temp = head->next;
    T erased = head->value;
    delete head;
    head = temp;
    size--;
    return erased;
  } else if (pos == size || pos == -1) {
    node<T> *temp = tail->previous;
    T erased = tail->value;
    delete tail;
    tail = temp;
    size--;
    return erased;
  } else if (pos > 0) {
    node<T> *temp = head, *auxPrev, *auxNext;
    T erased;
    for (int i = 0; i < pos - 1; i++) {
      if (temp->next == NULL) {
        return temp->value;
      }
      temp = temp->next;
    }
    auxPrev = temp->previous;
    auxNext = temp->next;
    auxPrev->next = auxNext;
    auxNext->previous = auxPrev;
    erased = temp->value;
    delete temp;
    size--;
    return erased;
  } else if (pos < 0) {
    node<T> *temp = tail, *auxPrev, *auxNext;
    T erased;
    for (int i = 0; i < (pos * -1) - 1; i++) {
      if (temp->previous == NULL) {
        return temp->value;
      }
      temp = temp->previous;
    }
    auxPrev = temp->previous;
    auxNext = temp->next;
    auxPrev->next = auxNext;
    auxNext->previous = auxPrev;
    erased = temp->value;
    delete temp;
    size--;
    return erased;
  }
}

/*
 * Elimina el elemento de la posición indicada y retorna la información de
 * este.
 */
T deletePos(int pos) {
  if (!validPosition(pos)) {
    throw std::out_of_range("Index out of range");
  } else if (pos == 1) {
    node<T> *temp = head->next;
    T erased = head->value;
    delete head;
    head = temp;
    size--;
    return erased;
  } else if (pos == size || pos == -1) {
    node<T> *temp = tail->previous;
    T erased = tail->value;
    delete tail;
    tail = temp;
    size--;
    return erased;
  } else {
    node<T> *temp, *toDelete;
    T erased;
    if (pos < 0) {
      temp = tail;
      for (int i = 1; i < (pos * -1); i++) {
        temp = temp->previous;
      }
    } else if (pos > 0) {
      temp = head;
      for (int i = 1; i < pos; i++) {
        temp = temp->next;
      }
    }
    toDelete = temp;
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    erased = toDelete->value;
    delete toDelete;
    size--;
    return erased;
  }
}

int length() { return size; }

std::string toString() {
  if (head == NULL)
    return "List []";
  std::string str = "List [";
  node<T> *aux = head;
  while (aux->next != NULL) {
    str += std::to_string(aux->value) + ", "; // para números
    // str += aux->value + ", ";
    aux = aux->next;
  }
  // str += aux->value;
  str += std::to_string(aux->value); // para números
  delete aux;
  return str + "]";
}
}
;

#endif
