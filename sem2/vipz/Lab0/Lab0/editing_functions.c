#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "deleting_functions.h"
#include "editing_functions.h"
#include "creating_functions.h"

double getAverage(const node_t* par_student) {
	return (par_student->ratings[0] +
			par_student->ratings[1] +
			par_student->ratings[2] +
			par_student->ratings[3] +
			par_student->ratings[4]) / 5.0;
}

void myLinkedListFilterByRatings(MyLinkedList* par_obj) {
	if (par_obj == NULL || par_obj->head == NULL) {
		printf("Wrong list given. There would be no output.");
		return;
	}

	int index = 0;
	const node_t* current = par_obj->head;
	while (current->next) {
		if (getAverage(current) > 4.5) {
			current = current->next;
			myLinkedListDeleteAtIndex(par_obj, index);
		} else {
			current = current->next;
			index++;
		}
	}

	if (getAverage(current) > 4.5) {
		myLinkedListDeleteAtIndex(par_obj, index);
	} else {
		index++;
	}
}

// season : winter - 1, spring - 2, summer - 3, autumn/fall - 4
int getBirthSeason(const node_t* par_student) {
	char temp[11];
	strcpy(temp, par_student->birthdate);
	strtok(temp, ".");
	const int birth_month = atoi(strtok(NULL, "."));
	switch (birth_month) {
	case 12:
	case 1:
	case 2: return 1;
	case 3:
	case 4:
	case 5: return 2;
	case 6:
	case 7:
	case 8: return 3;
	case 9:
	case 10:
	case 11: return 4;
	default: return 0;
	}
}

void myLinkedListFilterByBirthSeason(MyLinkedList* par_obj, int par_season) {
	if (par_obj == NULL || par_obj->head == NULL) {
		printf("Wrong list given. There would be no output.");
		return;
	}

	int index = 0;
	const node_t* current = par_obj->head;

	while (current->next) {
		if (getBirthSeason(current) != par_season) {
			current = current->next;
			myLinkedListDeleteAtIndex(par_obj, index);
		} else {
			current = current->next;
			index++;
		}
	}

	if (getBirthSeason(current) != par_season) {
		myLinkedListDeleteAtIndex(par_obj, index);
	} else {
		index++;
	}
}

MyLinkedList* myLinkedListSortByAverageAscending(MyLinkedList* par_obj) {
	if (par_obj == NULL || par_obj->head == NULL) {
		return par_obj;
	}

	MyLinkedList* new_list = myLinkedListCreate();
	double max = 0;
	node_t* max_node_prev = NULL;
	node_t* current = NULL;
	while (par_obj->head != NULL) {
		max_node_prev = NULL;
		current = par_obj->head;
		max = getAverage(current);

		while (current->next != NULL) {
			if (getAverage(current->next) > max) {
				max = getAverage(current->next);
				max_node_prev = current;
			}

			current = current->next;
		}

		if (max_node_prev == NULL) {
			current = par_obj->head;
			par_obj->head = current->next;
			current->next = new_list->head;
			new_list->head = current;
		} else {
			current = max_node_prev->next;
			max_node_prev->next = current->next;
			current->next = new_list->head;
			new_list->head = current;
		}
	}

	myLinkedListFree(par_obj);
	return new_list;
}
