#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
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
    printf("Прямой выбор %d: %lf\n", elems, (double)(t2-t1)/CLOCKS_PER_SEC);

    writeToFile(output2, &head, &tail);

    Node* head2 = NULL;
    Node* tail2 = NULL;

    readFromFileQueue(filename, &head2, &tail2);

    t1 = clock();
    quickSort(&head2, &tail2);
    t2 = clock();
    printf("Быстрая сортировка %d: %lf\n", elems, (double)(t2-t1)/CLOCKS_PER_SEC);

    writeToFile(output3, &head2, &tail2);

    freeQueue(&head, &tail);
    freeQueue(&head2, &tail2);
}

int main(int argc, char* argv[]) {
    setlocale(LC_CTYPE, "Russian");
    int have_args = 0;
    char repeat;
    clock_t t1;
    clock_t t2;
    if (argc == 3 && strcmp(argv[1], "--file") == 0) {
        have_args = 1;
        Node* head = NULL;
        Node* tail = NULL;
        Node* p;

        readFromFileQueue(argv[2], &head, &tail);
        p = head;
        printf("Очередь: ");
        while (p != NULL) {
            printf("%d ", p->value);
            p = p->next;
        }
        printf("\n");

        quickSort(&head, &tail);

        p = head;
        printf("Очередь: ");
        while (p != NULL) {
            printf("%d ", p->value);
            p = p->next;
        }
        printf("\n");
        
        freeQueue(&tail, &head);
    }
    do {
        Node* head = NULL;
        Node* tail = NULL;
        Node* p;

        readFromConsole(&head, &tail);
        if (head == NULL || tail == NULL) {
            printf("Некорректный ввод\n");
        }
        else {
            p = head;
            printf("Очередь: ");
            while (p != NULL) {
                printf("%d ", p->value);
                p = p->next;
            }
            printf("\n");

            writeToFile("output1.txt", &head, &tail);

            t1 = clock();
            selectionSort(&head, &tail);
            t2 = clock();
            printf("Прямой выбор: %lf\n", (double)(t2-t1)/CLOCKS_PER_SEC);

            p = head;
            printf("Очередь: ");
            while (p != NULL) {
                printf("%d ", p->value);
                p = p->next;
            }
            printf("\n");

            writeToFile("output2_sort.txt", &head, &tail);
        }

        Node* head2 = NULL;
        Node* tail2 = NULL;

        readFromConsole(&head2, &tail2);
        if (head2 == NULL || tail2 == NULL) {
            printf("Некорректный ввод\n");
        }
        else {
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
            printf("Быстрая сортировка: %lf\n", (double)(t2-t1)/CLOCKS_PER_SEC);

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


        // test_data("data_1000.txt", "output1000.txt", 
        //     "output1000_sel_sort.txt", "output1000_quick_sort.txt", 1000);


        // test_data("data_10000.txt", "output10000.txt", 
        //     "output10000_sel_sort.txt", "output10000_quick_sort.txt", 10000);


        // test_data("data_20000.txt", "output20000.txt", 
        //     "output20000_sel_sort.txt", "output20000_quick_sort.txt", 20000);


        // test_data("data_50000.txt", "output50000.txt", 
        //     "output50000_sel_sort.txt", "output50000_quick_sort.txt", 50000);


        // test_data("data_100000.txt", "output100000.txt", 
        //     "output100000_sel_sort.txt", "output100000_quick_sort.txt", 100000);

        if (have_args == 0) {
            printf("Повторить? (0 - нет, другое - да): ");
            scanf("%c", &repeat);
        }

    } while(have_args == 0 && repeat != '0');

}