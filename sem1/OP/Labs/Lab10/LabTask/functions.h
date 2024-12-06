#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Node {
    char firstname[20];
    char lastname[20];
    char birthDate[11];
    double average;
    
    struct Node* prev;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    struct Node* tail;
} MyLinkedList;

MyLinkedList* createList();

void addAtHead(MyLinkedList*, char[20], char[20], char[11], double);

void addAtTail(MyLinkedList*, char[20], char[20], char[11], double);

void deleteWithCondition(MyLinkedList*);

void freeList(MyLinkedList*);

#endif