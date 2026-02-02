#include "sort.h"

#include <stdlib.h>

void selectionSort(Node** head, Node** tail) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        return NULL;
    }

    Node* min;
    Node* p;
    Node* q = *head;
    
    while(q != NULL) {
        min = q;
        p = min->next;
        while (p != NULL) {
            if (p->value < min->value) {
                min = p;
            }
            p = p->next;
        }
        if (min->value < q->value) {
            int t = min->value;
            min->value = q->value;
            q->value = t;
        }
        q = q->next;
    }
}

Node* partition(Node** head, Node* tail,
                Node** newHead, Node** newTail) {

    Node* p = tail;
    Node* prev = NULL;
    Node* cur = *head;
    Node* end = tail;

    while (cur != p) {
        if (cur->value < p->value) {
            if (*newHead == NULL)
                *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;
            else
                *head = cur->next;

            Node* tmp = cur->next;
            cur->next = NULL;
            end->next = cur;
            end = cur;
            cur = tmp;
        }
    }

    if (*newHead == NULL)
        *newHead = p;

    *newTail = end;
    return p;
}

Node* quickSortRec(Node* head, Node* tail) {
    if (!head || head == tail)
        return head;

    Node* newHead = NULL;
    Node* newTail = NULL;

    Node* p = partition(&head, tail, &newHead, &newTail);

    if (newHead != p) {
        Node* t = newHead;
        while (t->next != p)
            t = t->next;

        t->next = NULL;

        newHead = quickSortRec(newHead, t);

        t = newHead;
        while (t->next)
            t = t->next;
        t->next = p;
    }

    p->next = quickSortRec(p->next, newTail);
    return newHead;
}

void fixTail(Node** head, Node** tail) {
    *tail = *head;
    while ((*tail)->next)
        *tail = (*tail)->next;
}


void quickSort(Node** head, Node** tail) {
    Node* end = *tail;
    *head = quickSortRec(*head, end);

    fixTail(head, tail);
}