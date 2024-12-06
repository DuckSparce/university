#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

#define DELETE_CONDITION (current->average > 45)

MyLinkedList* createList() {
    MyLinkedList* result = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    result->head = NULL;
    result->tail = NULL;
    return result;
}

void addAtHead(MyLinkedList* obj, char firstname[20], char lastname[20], char birthDate[11], double average) {
    if (obj) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode) {
            strcpy(newNode->firstname, firstname);
            strcpy(newNode->lastname, lastname);
            strcpy(newNode->birthDate, birthDate);
            newNode->average = average;

            newNode->next = obj->head;
            newNode->prev = NULL;
            obj->head = newNode;
        }
    }
}

void addAtTail(MyLinkedList* obj, char firstname[20], char lastname[20], char birthDate[11], double average) {
    if (obj) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode) {
            strcpy(newNode->firstname, firstname);
            strcpy(newNode->lastname, lastname);
            strcpy(newNode->birthDate, birthDate);
            newNode->average = average;

            newNode->next = NULL;
            newNode->prev = obj->tail;
            obj->tail = newNode;
        }
    }
}

void deleteWithCondition(MyLinkedList* obj) {
    if (obj && obj->head) {
        struct Node* current = obj->head;
        while (current->next) {
            if (DELETE_CONDITION) {
                struct Node* temp = current;
                struct Node* prev = current->prev;
                struct Node* next = current->next;

                prev->next = next;
                next->prev = prev;

                free(temp);
                current = next;
            } else {
                current = current->next;
            }
        }

        if (DELETE_CONDITION) {
            struct Node* temp = current;
            struct Node* prev = current->prev;
            struct Node* next = current->next;

            prev->next = next;
            next->prev = prev;

            free(temp);
            current = NULL;
        }
    }
}

void freeList(MyLinkedList* obj) {
    if (obj) {
        struct Node* current = obj->head;
        while (current) {
            struct Node* next = current->next;
            free(current);
            current = next;
        }
        free(obj->head);
    }
    free(obj);
}