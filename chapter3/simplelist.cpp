// Non-class based generic implementation of List.

#include <iostream>
#include <ctime>
#include <cstdlib>

template<typename Item>
struct Node {
    Item item;
    Node *next;

    Node(Item item, Node *next = nullptr) : item(item), next(next) {};
};

template<typename Item>
Node<Item> *add(Item item, Node<Item> *x) {
    Node<Item> *t = new Node<Item>(item);
    if (x != nullptr) t->next = x;
    return t;
}

template<typename Item>
Node<Item> *reverse(Node<Item> *x) {
    Node<Item> *y = x;
    x = y->next;
    y->next = 0;
    while (x != 0) {
        Node<Item> *t = x;
        x = x->next;
        t->next = y;
        y = t;
    }
    return y;
}

template<typename Item>
void deleteList(Node<Item> *x) {
    while (x != 0) {
        Node<Item> *t = x;
        x = x->next;
        delete (t);
    }
}

template<typename Item>
void show(Node<Item> *x) {
    Node<Item> *t = x;
    int count = 0;
    while (t != 0) {
        std::cout << "|" << t->item << "| -> ";
        t = t->next;
        count += 1;
    }
    std::cout << "nullptr\nCount: " << count << std::endl;
}

int main() {
    Node<int> *x = 0;
    srand(time(NULL));
    int N = 10;
    for (int i = 0; i < N; ++i) {
        x = add(rand() % N + 1, x);
    }
    show(x);
    x = reverse(x);
    show(x);
    deleteList(x);
}

