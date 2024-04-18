#ifndef MULTILIST_H
#define MULTILIST_H

#include <string>

struct Student {
	int age;
	std::string name, major, activity;
	int nextAge, nextName, nextMajor, nextActivity;

};

struct Node {
  std::string name;
	int head;
};

template <typename T>
class MultiList {
	private:
	Node *headers;
	Student *students;
	int size;

	public:
	MultiList() {
		int length = 10;
		headers = new Node[length];
		headers[0].name = "ages";
		headers[1].name = "names";
		headers[2].name = "cat";
		headers[3].name = "ele";
		headers[4].name = "ind";
		headers[5].name = "sis";
		headers[6].name = "basketball";
		headers[7].name = "bolevol";	
		headers[8].name = "danza";
		headers[9].name = "natación";	
		for (int i = 0; i < length; i++) {
			headers[i].head = -1;	
		}
		students = new Student[10];
		size = 0;
	}

//	MultiList() {
//		head = new Node<T>();
//		Node<T> *temp = head;
//		for (int i = 0; i < 3; i++) {
//			temp->next = new Node<T>();
//			temp->child = new Node<T>();
//			temp->child->next = new Node<T>();
//			temp->child->value = 0;
//			temp->child->next->value = 0;
//			temp->
//			temp->value = 0;
//			temp = temp->next;
//		}
//		temp->child = new Node<T>();
//		temp->value = 0;
//		temp->next = 0;
//	}
//
//	void addOL(T e) {
//		Node<T> *temp = head->child;
//		while(temp->next->next != temp->next) {
//			if(e > temp->value)
//				temp = temp->next;	
//		}
//		Node<T> *aux = new Node<T>();
//		aux->value = temp->value;
//		aux->child = 0;
//		aux->next = temp->next;
//		temp->value = e;
//		temp->next = aux;
//	}

	void addOL(Student *s) {
		if (headers[2].head == -1) {
			headers[2].head = size;
		} else {
			int current = headers[2].head;
			while(students[current].nextAge != -1 && s->age > students[current].age) {
				current = students[current].nextAge;
			}
		}
	}

	void addS(T e) {

	}

	void addROL(T e) {

	}
	
	void addQ(T e) {

	}
};

#endif
