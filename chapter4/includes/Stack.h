//
// Created by Santhoshkumar Settipalli on 19/07/18.
//

#ifndef CALGORITHMS_STACK_H
#define CALGORITHMS_STACK_H

template <typename Item>
class Stack {
private:
    struct Node {
        Node(Item item, Node *next);

        Item item;
        Node *next;
    };
    Node *head;
public:
    Stack(int);
    int empty() const;
    void push(Item item);
    Item pop();

};


#endif //CALGORITHMS_STACK_H
