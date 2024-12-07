#ifndef EDITING_FUNCTIONS_H_
#define EDITING_FUNCTIONS_H_

double getAverage(const node_t*);

void myLinkedListFilterByRatings(MyLinkedList*);

int getBirthSeason(const node_t*);

void myLinkedListFilterByBirthSeason(MyLinkedList*, int);

MyLinkedList* myLinkedListSortByAverageAscending(MyLinkedList*);

#endif // EDITING_FUNCTIONS_H_