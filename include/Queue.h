#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

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
			head->value = 0;
			tail->next = tail;
			tail->value = 0;
	}

		bool isEmpty() {
			return size == 0;
		}

		void enqueue (T e) {
			tail->next = new Node<T>();
			tail->value = e;
			tail = tail->next;
			tail->next = tail;
			tail->value = 0;
			size++;
		}

		T denqueue () {	
			Node<T> *temp = head->next;
			T e = temp->value;
			head->next = head->next->next;
			delete temp;
			size--;
			return e;
		}
};

#endif
