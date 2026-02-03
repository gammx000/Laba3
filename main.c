#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"
#include "queue.h"
#include "io.h"

void test_data(const char* filename, const char* output1, 
    const char* output2, const char* output3, int elems) {
    Node* head = NULL;
    Node* tail = NULL;

    readFromFileQueue(filename, &head, &tail);

    writeToFile(output1, &head, &tail);

    clock_t t1 = clock();
    selectionSort(&head, &tail);
    clock_t t2 = clock();
    printf("Selection %d: %.20lf\n", elems, (double)(t2-t1)/CLOCKS_PER_SEC);

    writeToFile(output2, &head, &tail);

    Node* head2 = NULL;
    Node* tail2 = NULL;

    readFromFileQueue(filename, &head2, &tail2);

    t1 = clock();
    quickSort(&head2, &tail2);
    t2 = clock();
    printf("Quick %d: %.20lf\n", elems, (double)(t2-t1)/CLOCKS_PER_SEC);

    writeToFile(output3, &head2, &tail2);

    freeQueue(&head, &tail);
    freeQueue(&head2, &tail2);
}

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

        clock_t t1 = clock();
        selectionSort(&head, &tail);
        clock_t t2 = clock();
        printf("Selection: %lf\n", (double)(t2-t1)/CLOCKS_PER_SEC);

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

        t1 = clock();
        quickSort(&head2, &tail2);
        t2 = clock();
        printf("Quick: %lf\n", (double)(t2-t1)/CLOCKS_PER_SEC);

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

        // first

        test_data("data_1000.txt", "output1000.txt", 
            "output1000_sel_sort.txt", "output1000_quick_sort.txt", 1000);

        // second

        test_data("data_10000.txt", "output10000.txt", 
            "output10000_sel_sort.txt", "output10000_quick_sort.txt", 10000);

        // third

        test_data("data_20000.txt", "output20000.txt", 
            "output20000_sel_sort.txt", "output20000_quick_sort.txt", 20000);

        // fourth

        test_data("data_50000.txt", "output50000.txt", 
            "output50000_sel_sort.txt", "output50000_quick_sort.txt", 50000);

        // fifth

        test_data("data_100000.txt", "output100000.txt", 
            "output100000_sel_sort.txt", "output100000_quick_sort.txt", 100000);
    }
    else {
        printf("Некорректные аргументы\n");
        return 0;
    }

}