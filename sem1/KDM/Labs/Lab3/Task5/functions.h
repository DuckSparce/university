#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void outputRelation(int**, int);

int isReflexive(int **, int);

int isSymmetric(int **, int);

int isTransitive(int **, int);

void analyseRelation(int **, int);

void task1();

int** findConverseRelation(int ** matrix, int size);

int** findComposition(int ** matrix1, int ** matrix2, int size);

void task2();

#endif