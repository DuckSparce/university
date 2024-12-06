#include <stdio.h>
#include <stdio.h>

typedef struct Node {
    int val;
    struct Node* next;
} node_t;

typedef struct {
    node_t* head;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* result = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    result->head = NULL;
    return result;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (obj == NULL || index < 0) {
        return -1;
    } else {
        int currentIndex = 0;
        node_t* currentNode = obj->head;
        while (currentIndex < index) {
            if (currentNode->next) {
                currentNode = currentNode->next;
                currentIndex++;
            } else {
                return -1;
            }
        }
        return currentNode->val;
    }
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if (obj) {
        node_t* newNode = (node_t*)malloc(sizeof(node_t));
        if (newNode) {
            newNode->val = val;
            newNode->next = obj->head;
            obj->head = newNode;
        }
    }
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (obj && obj->head) {
        node_t* currentNode = obj->head;
        while (currentNode->next) {
            currentNode = currentNode->next;
        }

        node_t* newNode = (node_t*)malloc(sizeof(node_t));
        if (newNode) {
            newNode->val = val;
            newNode->next = NULL;
            currentNode->next = newNode;
        }
    }
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (obj == NULL || index < 0) {
        return;
    } else if (index == 0) {
        myLinkedListAddAtHead(obj, val);
    } else {   
        int currentIndex = 0;
        node_t* currentNode = obj->head;
        
        while (currentIndex < index - 1) {
            if (currentNode->next) {
                currentNode = currentNode->next;
                currentIndex++;
            } else {
                return;
            }
        }

        node_t* newNode = (node_t*)malloc(sizeof(node_t));
        if (newNode) {
            newNode->val = val;
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (obj == NULL || index < 0) {
        return;
    } else if (index == 0) {
        free(obj->head);
        obj->head = NULL;
    } else {
        int currentIndex = 0;
        node_t* currentNode = obj->head;
        
        while (currentIndex < index - 1) {
            if (currentNode->next) {
                currentNode = currentNode->next;
                currentIndex++;
            } else {
                return;
            }
        }

        if (currentNode->next) {
            if (currentNode->next->next) {
                currentNode->next = currentNode->next->next;
            } else {
                free(currentNode->next);
                currentNode->next = NULL;
            }
        }
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    if (obj) {
        node_t* current = obj->head;
        while (current) {
            node_t* next = current->next;
            free(current);
            current = next;
        }
        free(obj);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/