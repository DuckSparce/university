#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "creating_functions.h"
#include "deleting_functions.h"
#include "editing_functions.h"
#include "io_functions.h"

// Main function:
// Input a list from console or file.
// Edit given list: filter students
// by ratings (delete those with an average of higher than 4.5),
// by birth season (keep only those who were born in summer),
// sort students by their average ratings ascending.
// Output a list to console or to file.
int main() {
	MyLinkedList* list = myLinkedListCreate();
	FILE* source;
	char source_file_name[50];
	FILE* destination = NULL;
	char destination_file_name[50];

	// List input
	int mode = 0;
	printf("Choose input mode (0 - console, 1 - file): ");
	scanf("%d", &mode);

	switch (mode) {
	case 0:
		source = stdin;
		printf("Input has such pattern:\n<Number of Students>\n");
		printf("<Firstname> <Lastname> <Birthdate>"
			"<5 Ratings in 5-point system>\n.\n.\n.\n");
		break;
	case 1:
		printf("Enter input file name: ");
		scanf("%s", source_file_name);
		source = fopen(source_file_name, "r");
		break;
	default:
		printf("Wrong input. End of a program.");
		return 1;
	}
	
	myLinkedListInput(list, source);

	// List editing
	printf("Creating a list...\n");
	printf("Filtering by rating (more than 4.5 are removed)...\n");
	myLinkedListFilterByRatings(list);
	printf("Filtering by birth season (summer) ...\n");
	myLinkedListFilterByBirthSeason(list, 3);
	printf("Sorting by average rating (ascending) ...\n");
	list = myLinkedListSortByAverageAscending(list);
	printf("The list editing is done!\n");

	// List output
	printf("Choose output mode (0 - console, 1 - file): ");
	scanf("%d", &mode);

	switch (mode) {
	case 0: destination = stdout;
		break;
	case 1:
		printf("Enter output file name: ");
		scanf("%s", destination_file_name);
		destination = fopen(destination_file_name, "w");
		break;
	default:
		printf("Wrong input. End of a program.");
		return 1;
	}

	myLinkedListOutput(list, destination);
	myLinkedListFree(list);
}
