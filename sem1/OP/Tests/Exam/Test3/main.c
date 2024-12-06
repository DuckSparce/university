#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Flat {
    char name[50];
    int number;
    int people;
    struct Flat * next;
};

struct List {
    struct Flat * head;
};

void addFlat(struct List * list, char name[50], int number, int people) {
    struct Flat * flat = (struct Flat *)malloc(sizeof(struct Flat));
    strcpy(flat->name, name);
    flat->number = number;
    flat->people = people;
    flat->next = NULL;

    if (list == NULL) {
        return;
    }

    struct Flat * current = list->head;
    while (current) {
        current = current->next;
    }
    current = flat;
}

void deleteFlat(struct List * list) {
    struct Flat * temp = list->head;
    list->head = temp->next;
    free(temp);
    temp = NULL;
}

void freeList(struct List * list) {
    while (list->head) {
        deleteFlat(list);
    }
    list = NULL;
}

void deleteFlatWithName(struct List * list, char surname[50], int * deletedResult, int * maxNumberResult) {
    int maxCount = 0;
    *deletedResult = 0;
    *maxNumberResult = 0;

    struct Flat * current = list->head;

    char tempsurname[50] = strtok(current->name, " ");
    if (!strcmp(tempsurname, surname)) {
        struct Flat * temp = current;
        list->head = temp->next;
        free(temp);
        (*deletedResult)++;
    }

    while (current->next) {
        if (current->people > maxCount) {
            maxCount = current->people;
            *maxNumberResult = current->number;
        }

        char tempsurname[50] = strtok(current->next->name, " ");
        if (!strcmp(tempsurname, surname)) {
            struct Flat * temp = current->next;
            current->next = current->next->next;
            free(temp);
            (*deletedResult)++;
        }
        current = current->next;
    }

    if (current->people > maxCount) {
        maxCount = current->people;
        *maxNumberResult = current->number;
    }
}

int main(int argc, char ** argv) {
    FILE* file = fopen(*argv, "r");
    // Surname Name Middlename, number, people
    char line[100];
    fgets(line, 100, file);
    int flatNumber = atoi(line);

    struct List flatList = {NULL};

    for (int i = 0; i < flatNumber; i++) {
        fgets(line, 100, file);
        char name[50] = strtok(line, ",");
        int number = atoi(strtok(line, ","));
        int people = atoi(strtok(line, ","));
        addFlat(&flatList, name, number, people);
    }

    int deletedTrust = 0;
    int maxNumber = 0;
    deleteFlatWithName(&flatList, "Trust", deletedTrust, maxNumber);

    //Output
    struct Flat * current = flatList.head;
    while (current) {
        printf("%s, %d, %d\n", current->name, current->number, current->people);
        current = current->next;
    }

    freeList(&flatList);
}