#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void push(Node* head, Node* tail, int a) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->value = a;
    n->next = NULL;

    if (tail == NULL) {
        head = n;
        tail = n;

        printf("head->value = %d\n", head->value);
        printf("tail->value = %d\n\n", tail->value);
    }
    else {
        tail->next = n;
        tail = n;
        printf("tail->value = %d\n\n", tail->value);
    }
    printf("push: head = %p\ntail = %p\n\n", head, tail);
}

int pop(Node* head, Node* tail) {
    if (head == NULL) {
        return 0;
    }

    Node* t = head;
    int value = t->value;
    head = head->next;
    free(t);
    if (head == NULL) {
        tail = NULL;
    }

    return value;
}

void freeQueue(Node* head, Node* tail) {
    while (head != NULL) {
        pop(head, tail);
    }
}
