#ifndef IO_H
#define IO_H
#include "queue.h"

int* readFromFile(const char* filename, int* n);
void readFromFileQueue(const char* filename, Node** head, Node** tail);
void readFromConsole(Node** head, Node** tail);
void writeToFile(const char* filename, Node** head, Node** tail);

#endif