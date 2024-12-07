#include <stdlib.h>

#include "structures.h"
#include "getting_functions.h"

node_t* myLinkedListGet(const MyLinkedList* par_obj, const int par_index) {
	if (par_obj == NULL || par_index < 0) {
		return NULL;
	}

	int current_index = 0;
	node_t* current_node = par_obj->head;

	while (current_index < par_index) {
		if (current_node->next) {
			current_node = current_node->next;
			current_index++;
		} else {
			return NULL;
		}
	}

	if (!current_node) {
		return NULL;
	}

	return current_node;
}