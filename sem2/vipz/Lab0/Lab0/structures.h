#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct Node {
	char firstname[20];
	char lastname[20];
	char birthdate[11];
	int ratings[5];

	struct Node* next;
} node_t;

typedef struct {
	node_t* head;
} MyLinkedList;

#endif // STRUCTURES_H