//
// Created by Santhoshkumar Settipalli on 19/07/18.
//

#include "includes/Stack.h"

template<typename Item>
Stack<Item>::Node::Node(Item item, Stack::Node *next):item(item), next(next) {}

template<typename Item>
Stack<Item>::Stack(int) {
    head = 0;
}

template<typename Item>
int Stack<Item>::empty() const {
    return head == 0;
}

template<typename Item>
void Stack<Item>::push(Item item) {
    head = new Node(item, head);
}

template<typename Item>
Item Stack<Item>::pop() {
    Item item = head->item;
    Node *t = head->next;
    delete head;
    head = t;
    return item;
}
