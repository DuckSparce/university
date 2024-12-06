#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char name[50];
    char author[50];
    int pages;
    int year;
    struct Book * next;
};

struct LinkedList {
    struct Book * head;
};

struct Book * createBook(char name[50], char author[50], int pages, int year) {
    struct Book * result = (struct Book *)malloc(sizeof(struct Book));
    strcpy(result->name, name);
    strcpy(result->author, author);
    result->pages = pages;
    result->year = year;
    result->next = NULL;
    return result;
}

struct LinkedList * createList(struct Book * head) {
    struct LinkedList * result = (struct List *)malloc(sizeof(struct LinkedList));
    result->head = head;
}

void addToList(struct LinkedList * list, struct Book * book) {
    if (list->head == NULL) {
        return;
    }

    struct Book * current = list->head;
    while (current -> next) {
        current = current->next;
    }

    current->next = book;
}

void freeList(struct LinkedList * list) {
    if (list == NULL || list->head == NULL) {
        return;
    }

    struct Book * current = list->head;
    while (current) {
        free(current);
        current = current->next;
    }
    free(current);
}

void function(struct LinkedList * list) {
    struct Book * current = list->head;
    struct Book * prevMaxPagesBook = NULL;
    int maxPages = current->pages;
    

    while (current->next) {
        if (current->next->pages > maxPages) {
            maxPages = current->next->pages;
            prevMaxPagesBook = current;
        }
        current = current->next;
    }

    if (!prevMaxPagesBook) {
        struct Book * temp = list->head;
        while (temp->next->next) {
            temp = temp->next;
        }
        temp->next = prevMaxPagesBook->next;
        
        prevMaxPagesBook->next = current;
        current->next = prevMaxPagesBook->next->next;

        temp->next->next = NULL;
    }

}

int main() {
    struct Book * book1 = createBook("Book1", "Author1", 150, 2000);
    struct Book * book2 = createBook("Book2", "Author2", 765, 1996);
    struct Book * book3 = createBook("Book3", "Author3", 549, 2010);
    struct Book * book4 = createBook("Book4", "Author4", 375, 1956);
    struct Book * book5 = createBook("Book5", "Author5", 299, 1980);

    struct LinkedList * bookList = createList(book1);
    addToList(bookList, book2);
    addToList(bookList, book3);
    addToList(bookList, book4);
    addToList(bookList, book5);

    function(bookList);

    freeList(bookList);
}