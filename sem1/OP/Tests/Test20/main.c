#include <stdio.h>

// typedef struct SPerson
// {
//     char mName[20];
//     int mAge;
// } SPerson;

// typedef struct SNode
// {
//     SPerson mPerson;
//     SNode * mpNext;
// } SNode;

int sum(int a, int b)
{
    return a+b;
}

// int sum(int a, int b, int c)
// {
//     return a+b+c;
// }

int main()
{
    printf("%d", sum(1, 2));
    // printf("%d", sum(1, 2, 3));
    

    // SNode* pHead = NULL;
    
    // SNode node1 = {{"Ivan", 20}, NULL};
    // pHead = &node1;
    // pHead -> mPerson.mAge = 21;

    // SNode * pNode2 = (SNode*)malloc(sizeof(SNode));
    // SPerson tempPerson = {"Oleh", 18};
    // pNode2->mPerson = tempPerson;
    // pNode2->mpNext = NULL;

    // node1.mpNext = pNode2;


}