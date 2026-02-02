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

void readFromConsole(Node* head, Node* tail) {
    printf("Числа: ");
    int a;
    while(scanf("%d", &a) == 1) {
        push(head, tail, a);
        printf("readFromConsole: head = %p\ntail = %p\n\n", head, tail);
        if (getchar() == '\n') {
            break;
        }
    }
}