#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    int price;
    int amount;
    struct Item * next;
};

struct Item * createItem(char name[50], int price, int amount) {
    struct Item * result = (struct Item *)malloc(sizeof(struct Item));
    
    strcpy(result->name, name);
    result->price = price;
    result->amount = amount;
    
    return result;
}

void addToList (struct Item * head, struct Item * item) {
    if (head == NULL) {
        return;
    }

    while (head->next) {
        head = head->next;
    }

    head->next = item;
}

void freeList(struct Item * head) {
    struct Item * temp = head;
    while (temp->next) {
        struct Item * next = temp->next;
        free(temp);
        temp = next;
    }
    free(temp);
}

void func(struct Item * head) {
    if (head == NULL) {
        return;
    }

    struct Item* current = head;
    struct Item* item3 = NULL;
    struct Item* maxItemPrev = NULL;
    int max = current->amount;

    int i = 1;
    while (current->next) {
        if (current->next->amount > max) {
            max = current->next->amount;
            maxItemPrev = current;
        }

        current = current->next;

        i++;
        if (i == 3) {
            item3 = current;
        }
    }
    
    //switch previous ones
    struct Item* temp = maxItemPrev->next;

    maxItemPrev->next = item3->next;
    item3->next = temp;

    //switch next ones
    temp = maxItemPrev->next->next;

    maxItemPrev->next->next = item3->next->next;
    item3->next->next = temp;
}

int main() {
    struct Item * item1 = createItem("Milk", 40, 15);
    struct Item * item2 = createItem("Bread", 15, 30);
    struct Item * item3 = createItem("Juice", 25, 20);
    struct Item * item4 = createItem("Gum", 10, 10);
    struct Item * item5 = createItem("Icecream", 20, 25);

    addToList(item1, item2);
    addToList(item1, item3);
    addToList(item1, item4);
    addToList(item1, item5);

    func(item1);

    freeList(item1);
    item1 = NULL;
}