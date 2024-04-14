#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack {
	private:
		Node<T> *head, *tail;

	public:
		Stack() {
			head = new Node<T>();
			tail = new Node<T>();
			head->next = tail;
			head->value = 0;
			tail->value = 0;
			tail->next = tail;
		}

		void push(T e) {
			Node<T> *temp = new Node<T>();
			temp->value = e;
			temp->next = head->next;
			head->next = temp;
			delete temp;
		}

		T pop() {
			if(isEmpty())
				throw std::out_of_range("Stack is empty, T pop()");
			Node<T> *temp = head->next;
			head->next = temp->next;
			T e = temp->value;
			delete temp;
			return e;
		}

		bool isEmpty() {
			return head->next == tail;
		}
};

#endif
