#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack {
	private:
		Node<T> *top, *bottom;

	public:
		Stack() {
			top = new Node<T>();
			bottom = new Node<T>();
			top->next = bottom;
		}

		void push(T e) {
			Node<T> *temp = new Node<T>();
			temp->value = e;
			temp->next = top->next;
			top->next = temp;
		}

		T pop() {
			if(isEmpty())
				throw std::out_of_range("Stack is empty, T pop()");
			Node<T> *temp = top->next;
			top->next = temp->next;
			T e = temp->value;
			delete temp;
			return e;
		}

		bool isEmpty() {
			return top->next == bottom;
		}

		~Stack() {
			Node<T> *aux;
			while(!isEmpty()) {
				while(!isEmpty()) {
				aux = top->next;
				top->next = aux->next;
				delete aux;
			}
			delete top;
			delete bottom;
			}
		}
};

#endif
