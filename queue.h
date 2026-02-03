#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void push(Node** head, Node** tail, int a);
int pop(Node** head, Node** tail);
void freeQueue(Node** head, Node** tail);

#endif