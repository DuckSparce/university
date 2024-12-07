#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "io_functions.h"
#include "creating_functions.h"

void myLinkedListInput(MyLinkedList* par_obj, FILE* par_source) {
	unsigned int count = 0;
	fscanf(par_source, "%u", &count);
	for (int i = 0; i < count; i++) {
		char firstname[20];
		char lastname[20];
		char birthdate[11];
		int ratings[5];

		fscanf(par_source, "%s %s %s %d %d %d %d %d\n",
			firstname, lastname,
			birthdate, ratings,
			ratings + 1, ratings + 2,
			ratings + 3, ratings + 4);
		firstname[19] = '\0';
		lastname[19] = '\0';

		if (!isValidDate(birthdate)) {
			printf("The date format of student #%d is incorrect. End of program.", i + 1);
			exit(1);
		}

		if (ratings[0] > 5 || ratings[0] < 1 ||
			ratings[1] > 5 || ratings[1] < 1 ||
			ratings[2] > 5 || ratings[2] < 1 ||
			ratings[3] > 5 || ratings[3] < 1 ||
			ratings[4] > 5 || ratings[4] < 1) {
			printf("The ratings of student #%d are out of range. End of program.", i + 1);
			exit(1);
		}

		myLinkedListAddAtTail(par_obj,
			firstname, lastname,
			birthdate, ratings[0],
			ratings[1], ratings[2],
			ratings[3], ratings[4]);
	}
}

void myLinkedListOutput(const MyLinkedList* par_obj, FILE* par_destination) {
	if (par_destination == NULL) {
		printf("There is no such file. No output.");
		return;
	}

	if (par_obj == NULL || par_obj->head == NULL) {
		fprintf(par_destination, "<Empty list>.");
		return;
	}

	// Count the students
	node_t* current = par_obj->head;
	int count = 0;

	while (current) {
		count++;
		current = current->next;
	}

	fprintf(par_destination, "%d\n", count);

	current = par_obj->head;
	for (int i = 0; i < count; i++) {
		fprintf(par_destination, "%s %s %s %d %d %d %d %d\n",
			current->firstname, current->lastname,
			current->birthdate, current->ratings[0],
			current->ratings[1], current->ratings[2],
			current->ratings[3], current->ratings[4]);
		current = current->next;
	}

	if (par_destination != stdout) {
		printf("The students data was successfully written to the given file.");
	}
}

int isValidDate(const char* str) {
	// Check if the string length is valid for a date
	if (strlen(str) != 10) {
		return 0;
	}

	// Check if the format is correct
	if (str[2] != '.' || str[5] != '.') {
		return 0;
	}

	// Check if each part is a number
	for (int i = 0; i < 10; i++) {
		if (i != 2 && i != 5) {
			if (str[i] < '0' || str[i] > '9') {
				return 0;
			}
		}
	}

	// Extract day, month, and year
	char day[3], month[3], year[5];
	strncpy(day, str, 2);
	day[2] = '\0';
	strncpy(month, str + 3, 2);
	month[2] = '\0';
	strncpy(year, str + 6, 4);
	year[4] = '\0';

	// Convert strings to integers for validation
	int dayNum = atoi(day);
	int monthNum = atoi(month);
	int yearNum = atoi(year);

	// Validate day, month, and year ranges
	if (dayNum < 1 || dayNum > 31 || monthNum < 1 || monthNum > 12 || yearNum < 1900 || yearNum > 2023) {
		return 0;
	}

	// Check for valid day in each month
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (monthNum == 2 && ((yearNum % 4 == 0 && yearNum % 100 != 0) || yearNum % 400 == 0)) {
		daysInMonth[1] = 29;  // Leap year
	}

	if (dayNum > daysInMonth[monthNum - 1]) {
		return 0;
	}

	return 1;  // Date is valid
}