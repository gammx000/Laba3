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