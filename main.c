#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "sort.h"
#include "io.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Некорректное кол-во аргументов\n");
        return 0;
    }
    else if (argc == 3 && strcmp(argv[1], "--file") == 0) {
        int n;
        int* arr = readFromFile(argv[2], &n);

        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr);

        Node* head = NULL;
        Node* tail = NULL;
        Node* p;

        readFromConsole(&head, &tail);
        p = head;
        printf("Очередь: ");
        while (p != NULL) {
            printf("%d ", p->value);
            p = p->next;
        }
        printf("\n");

        writeToFile("output1.txt", &head, &tail);

        selectionSort(&head, &tail);

        p = head;
        printf("Очередь: ");
        while (p != NULL) {
            printf("%d ", p->value);
            p = p->next;
        }
        printf("\n");

        writeToFile("output2_sort.txt", &head, &tail);

        Node* head2 = NULL;
        Node* tail2 = NULL;

        readFromConsole(&head2, &tail2);
        p = head2;
        
        printf("Очередь 2: ");
        while (p != NULL) {
            printf("%d ", p->value);
            p = p->next;
        }
        printf("\n");

        quickSort(&head2, &tail2);

        p = head2;
        printf("Очередь 2: ");
        while (p != NULL) {
            printf("%d ", p->value);
            p = p->next;
        }
        printf("\n");

        writeToFile("output3_sort.txt", &head2, &tail2);

        freeQueue(&head, &tail);
        freeQueue(&head2, &tail2);
    }
    else {
        printf("Некорректные аргументы\n");
        return 0;
    }

}