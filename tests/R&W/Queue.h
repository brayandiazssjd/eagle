#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <stdexcept>

template <typename T>
class Queue {
	private:
		Node<T> *head, *tail;
    int size;

	public:
		Queue() {
			head = new Node<T>();
			tail = new Node<T>();
			head->next = tail;
      size = 0;
		}

		bool isEmpty() {
			return size == 0;
		}

		void enqueue (T e) {
			tail->next = new Node<T>();
			tail->value = e;
			tail = tail->next;
      size++;
		}

		T denqueue () {
			if(isEmpty())
				throw std::out_of_range("The queue is isEmpty");
			Node<T> *temp = head->next;
			head->next = temp->next;
			T e = temp->value;
			delete temp;
			size--;
			return e;
		}

		~Queue() {
			Node<T> *aux;
			while(!isEmpty()) {
				aux = head->next;
				head->next = aux->next;
				delete aux;
			}
			delete head;
			delete tail;
		}
  
    int length() {
      return size;
    }
};

#endif
