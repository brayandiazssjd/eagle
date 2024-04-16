#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <typename T>
class Queue {
	private:
		Node<T> *head, *tail;
		int size;

	public:
		bool isEmpty() {
			return size == 0;
		}

		void enqueue (T e) {

		}

		T denqueue () {

		}
};

#endif
