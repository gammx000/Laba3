#include "io.h"
#include <stdlib.h>
#include <stdio.h>

int* readFromFile(const char* filename, int* n) {
    FILE* f = fopen(filename, "r");

    *n = 0;
    int a;

    while(fscanf(f, "%d", &a) == 1) {
        (*n)++;
    }

    rewind(f);

    int* arr = (int*)malloc(sizeof(int) * (*n));
    for (int i = 0; i < (*n); i++) {
        fscanf(f, "%d", &arr[i]);
    }

    fclose(f);
    return arr;
}

void readFromFileQueue(const char* filename, Node** head, Node** tail) {
    FILE* f = fopen(filename, "r");

    int a;
    while(fscanf(f, "%d", &a) == 1) {
        push(head, tail, a);
    }

    fclose(f);
}

void readFromConsole(Node** head, Node** tail) {
    printf("Числа: ");
    int a;
    while(scanf("%d", &a) == 1) {
        push(head, tail, a);
        if (getchar() == '\n') {
            break;
        }
    }
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void writeToFile(const char* filename, Node** head, Node** tail) {
    FILE* f = fopen(filename, "w");

    Node* p = *head;
    while (p != NULL) {
        fprintf(f, "%d ", p->value);
        p = p->next;
    }

    fclose(f);
}