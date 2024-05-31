#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
struct BNode {
    T value;
    int r;
    int l;
};

template <typename T>
class Tree {
private:
    BNode<T>* trunk;
    int size;

public:
    Tree(int size) {
        this->size = size;
        trunk = new BNode<T>[size + 1];
        for (int i = 0; i <= size; i++) {
            trunk[i].r = (i + 1) % (size + 1);
            trunk[i].l = 0;
            if (i != 0) {
                trunk[i].value = nullptr;
            }
        }
        trunk[0].l = 0;
        trunk[0].r = 1;
    }

    ~Tree() {
        delete[] trunk;
    }

    void add(T e) {
        int pos = trunk[0].r;
        if (pos == 0) {
            cout << "Tree is full" << endl;
            return;
        }
        trunk[0].r = trunk[pos].r;
        trunk[pos].value = e;
        trunk[pos].r = 0;

        int parent = 0;
        int current = trunk[0].l;
        while (current != 0) {
            parent = current;
            if (e->getId() < trunk[current].value->getId()) {
                current = trunk[current].l;
            } else {
                current = trunk[current].r;
            }
        }

        if (parent == 0) {
            trunk[0].l = pos;
        } else if (e->getId() < trunk[parent].value->getId()) {
            trunk[parent].l = pos;
        } else {
            trunk[parent].r = pos;
        }
    }

    void inOrder() {
        if (trunk[0].l == 0) {
            cout << "Tree is empty" << endl;
            return;
        }

        stack<int> s;
        int current = trunk[0].l;

        while (current != 0 || !s.empty()) {
            while (current != 0) {
                s.push(current);
                current = trunk[current].l;
            }
            current = s.top();
            s.pop();

            cout << trunk[current].value->getId() << " ";  // Asegúrate de imprimir el ID del estudiante
            current = trunk[current].r;
        }
        cout << endl;
    }

    bool contains(T value) {
        int current = trunk[0].l; 
        while (current != 0) {
            if (trunk[current].value->getId() == value->getId()) {
                return true;
            } else if (value->getId() < trunk[current].value->getId()) {
                current = trunk[current].l;
            } else {
                current = trunk[current].r;
            }
        }
        return false;
    }

    bool findBool(long id) {
        int current = trunk[0].l;
        while (current != 0) {
            if (trunk[current].value->getId() == id) {
                return true;
            } else if (id < trunk[current].value->getId()) {
                current = trunk[current].l;
            } else {
                current = trunk[current].r;
            }
        }
        return false;
    }

    T find(long id) {
        int current = trunk[0].l;
        while (current != 0) {
            if (trunk[current].value->getId() == id) {
                return trunk[current].value;
            } else if (id < trunk[current].value->getId()) {
                current = trunk[current].l;
            } else {
                current = trunk[current].r;
            }
        }
        return nullptr;
    }
};

