#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "functions.h"

#define MAX_CHARS 100
#define STUDENTS_COUNT 7

int main() {
    MyLinkedList* list = createList();

    FILE* source = fopen("students.txt", "r");
    if (source == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return EXIT_FAILURE;
    }

    char line[MAX_CHARS];
    fgets(line, MAX_CHARS, source);

    for (int i = 0; i < STUDENTS_COUNT; i++) {
        char firstname[20];
        char lastname[20];
        char birthDate[11];
        int marks[5];

        sscanf(line, "%19[^,], %19[^,], %10[^,], %d, %d, %d, %d, %d",
           lastname, firstname, birthDate,
           marks, marks + 1, marks + 2,
           marks + 3, marks + 4);

        printf("Reading: %s, %s, %s, %d, %d, %d, %d, %d     . . .     ",
           lastname, firstname, birthDate,
           marks[0], marks[1], marks[2],
           marks[3], marks[4]);
        
        double average = (marks[0] + marks[1] + marks[2] + marks[3] + marks[4]) / 5.0;
        addAtTail(list, firstname, lastname, birthDate, average);
        Sleep(1);

        printf("done.\n");

        fgets(line, MAX_CHARS, source);
    }

    freeList(list);
}