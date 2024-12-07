#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "creating_functions.h"

MyLinkedList* myLinkedListCreate() {
	MyLinkedList* result = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	if (result) {
		result->head = NULL;
	}
	return result;
}

void myLinkedListAddAtHead(
		MyLinkedList* par_obj,
		char par_firstname[20],
		char par_lastname[20],
		char par_birthdate[11],
		int par_rating1,
		int par_rating2,
		int par_rating3,
		int par_rating4,
		int par_rating5) {
	if (par_obj) {
		node_t* newNode = (node_t*)malloc(sizeof(node_t));

		if (newNode) {
			strcpy(newNode->firstname, par_firstname);
			strcpy(newNode->lastname, par_lastname);
			strcpy(newNode->birthdate, par_birthdate);

			newNode->ratings[0] = par_rating1;
			newNode->ratings[1] = par_rating2;
			newNode->ratings[2] = par_rating3;
			newNode->ratings[3] = par_rating4;
			newNode->ratings[4] = par_rating5;

			newNode->next = par_obj->head;
			par_obj->head = newNode;
		}
	}
}

void myLinkedListAddAtTail(
		MyLinkedList* par_obj,
		char par_firstname[20],
		char par_lastname[20],
		char par_birthdate[11],
		int par_rating1,
		int par_rating2,
		int par_rating3,
		int par_rating4,
		int par_rating5) {
	if (par_obj) {
		node_t* newNode = (node_t*)malloc(sizeof(node_t));

		if (newNode) {
			strcpy(newNode->firstname, par_firstname);
			strcpy(newNode->lastname, par_lastname);
			strcpy(newNode->birthdate, par_birthdate);

			newNode->ratings[0] = par_rating1;
			newNode->ratings[1] = par_rating2;
			newNode->ratings[2] = par_rating3;
			newNode->ratings[3] = par_rating4;
			newNode->ratings[4] = par_rating5;

			newNode->next = NULL;
		}

		if (par_obj->head) {
			node_t* currentNode = par_obj->head;

			while (currentNode->next) {
				currentNode = currentNode->next;
			}

			currentNode->next = newNode;
		} else {
			par_obj->head = newNode;
		}
	}
}

void myLinkedListAddAtIndex(
		MyLinkedList* par_obj,
		int par_index,
		char par_firstname[20],
		char par_lastname[20],
		char par_birthdate[11],
		int par_rating1,
		int par_rating2,
		int par_rating3,
		int par_rating4,
		int par_rating5) {
	if (par_obj == NULL || par_index < 0) {
		return;
	} else if (par_index == 0) {
		myLinkedListAddAtHead(par_obj, par_firstname, par_lastname, par_birthdate,
			par_rating1, par_rating2, par_rating3, par_rating4, par_rating5);
	} else {
		int currentIndex = 0;
		node_t* currentNode = par_obj->head;

		while (currentIndex < par_index - 1) {
			if (currentNode && currentNode->next) {
				currentNode = currentNode->next;
				currentIndex++;
			} else {
				return;
			}
		}

		node_t* newNode = (node_t*)malloc(sizeof(node_t));

		if (newNode && currentNode) {
			strcpy(newNode->firstname, par_firstname);
			strcpy(newNode->lastname, par_lastname);
			strcpy(newNode->birthdate, par_birthdate);

			newNode->ratings[0] = par_rating1;
			newNode->ratings[1] = par_rating2;
			newNode->ratings[2] = par_rating3;
			newNode->ratings[3] = par_rating4;
			newNode->ratings[4] = par_rating5;

			newNode->next = currentNode->next;
			currentNode->next = newNode;
		}
	}
}