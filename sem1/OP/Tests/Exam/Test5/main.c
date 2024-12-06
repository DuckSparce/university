#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char nick[50];
    int birthYear;
    struct User* prev;
    struct User* next;
};

struct List {
    struct User* head;
    struct User* tail;
};

void addUser(struct List* list, char nick[50], int birthYear) {
    if (list == NULL) return;
    
    struct User* user = (struct User*)malloc(sizeof(struct User));
    strcpy(user->nick, nick);
    user->birthYear = birthYear;
    user->prev = list->tail;
    user->next = NULL;
    list->tail = user;
    if (list->head == NULL) {
        list->head = user;
    }
}

void function(struct List * list, int* youngestYear, int* changed) {
    if(list == NULL) return;
    struct User * current = list->head;
    int year; struct User * preYoungest;
    while (current->next->next) {
        if (current->next->birthYear > year) {
            year = current->next->birthYear;
            preYoungest = current;
            (*changed)++;
        }
        current = current->next;
    }
    *youngestYear = year;

    struct User * youngest = preYoungest->next;
    preYoungest->next = NULL;
    youngest->prev = NULL;
    struct Student * temp = list->head;
    list->head->prev = list->tail;
    list->tail->next = temp;
}

void FreeListElem(struct List* list) {
    struct User* temp = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;

    temp = NULL;
    free(temp);
}

int main(int argc, char * argv[]) {
    char sCount[50] = argv[1];
    strtok(sCount, "=");
    int count = atoi(strtok(sCount, "="));

    char * fileName = argv[2];
    strtok(fileName, "=");
    fileName = strtok(fileName, "=");

    struct List list = {NULL, NULL};

    FILE * file = fopen(fileName, "r");
    for (int i = 0; i < count; i++) {
        char nick[50];
        int birthYear;
        fscanf(file, "%s, %d", &nick, &birthYear);
        addUser(&list, nick, birthYear);
    }

    int birthResult = 0;
    int number = 0;
    
    function(&list, &birthResult, &number);

    printf("birthResult = %d\nnumber = %d\n", birthResult, number);
    
    for (int i = 0; i < count; i++) {
        struct User * current = list.head;
        printf("%s %d\n", current->nick, current->birthYear);
        current = current->next;
    }

    for (int i = 0; i < count; i++) {
        FreeListElem(&list);
    }
}