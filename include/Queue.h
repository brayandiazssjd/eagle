#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <typename T>
class Queue {
	private:
		Node<T> *head, *tail;

	public:
		Queue() {
			head = new Node<T>();
			tail = new Node<T>();
			head->next = tail;
		}

		bool isEmpty() {
			return head->next == tail;
		}

		void enqueue (T e) {
			tail->next = new Node<T>();
			tail->value = e;
			tail = tail->next;
		}

		T denqueue () {	
			Node<T> *temp = head->next;
			head->next = temp->next;
			T e = temp->value;
			delete temp;
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
};

#endif
