#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char lastName[25];
    char firstName[25];
    int birthYear;
    struct Student * next;
};

struct List {
    struct Student * head;
};

// add student to the end of list
void addStudent(struct List * list, char lastName[25], char firstName[25], int birthYear) {
    struct Student * newStudent = (struct Student *)malloc(sizeof(struct Student));
    strcpy(newStudent->lastName, lastName);
    strcpy(newStudent->firstName, firstName);
    newStudent->birthYear = birthYear;
    newStudent->next = NULL;

    if (list->head == NULL) {
        list->head = newStudent;
    } else {
        struct Student * current = list->head;

        while (current->next) {
            current = current->next;
        }

        current->next = newStudent;
    }
}

void FreeLastElem(struct List * list) {
    struct Student * current = list->head;

    if (current->next == NULL) {
        free(current);
        list->head = NULL;
    }

    while (current->next->next) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void function(struct List * list, int* youngestYear, int* firstYear) {
    struct Student * current = list->head;
    *firstYear = current->birthYear;

    struct Student * preYoungest = NULL;
    int maxYear = 0;

    while (current->next) {
        if (current->next->birthYear > maxYear) {
            maxYear = current->next->birthYear;
            preYoungest = current;
        }
    }

    preYoungest->next = preYoungest->next->next;
    preYoungest->next->next = list->head;
}

int main(int argc, char ** argv) {
    int n = atoi(atoi(argv[1]));

    FILE* file = fopen(argv[2], "r");
    struct List * list = {NULL};
    char line[100];
    
    for (int i = 0; i < n; i++) {
        fgets(line, 100, file);
        char lastName[25] = strtok(line, ", ");
        char firstName[25] = strtok(NULL, ", ");
        int birthYear = atoi(strtok(NULL, ", "));
        addStudent(list, lastName, firstName, birthYear);
    }

    int youngestYearResult = 0;
    int firstYearResult = 0;

    function(list, &youngestYearResult, &firstYearResult);

    while (list->head) {
        FreeLastElem(list);
    }
    list = NULL;
}