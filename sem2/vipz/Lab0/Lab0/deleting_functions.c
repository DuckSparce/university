#include <stdlib.h>

#include "structures.h"
#include "deleting_functions.h"

void myLinkedListDeleteAtIndex(MyLinkedList* par_obj, int par_index) {
	if (par_obj == NULL || par_obj->head == NULL || par_index < 0) {
		return;
	}

	if (par_index == 0) {
		node_t* temp = par_obj->head->next;
		free(par_obj->head);
		par_obj->head = temp;
		return;
	}

	int current_index = 0;
	node_t* current_node = par_obj->head;

	while (current_index < par_index - 1) {
		if (current_node->next) {
			current_node = current_node->next;
			current_index++;
		} else {
			return;
		}
	}

	if (current_node->next) {
		if (current_node->next->next) {
			node_t* temp = current_node->next;
			current_node->next = current_node->next->next;
			free(temp);
		} else {
			free(current_node->next);
			current_node->next = NULL;
		}
	}
}

void myLinkedListFree(MyLinkedList* par_obj) {
	if (par_obj) {
		node_t* current = par_obj->head;
		while (current) {
			node_t* next = current->next;
			free(current);
			current = next;
		}
		free(par_obj);
	}
}