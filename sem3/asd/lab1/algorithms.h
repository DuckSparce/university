#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// CPP standard libraries
#include <cstddef>

// QT libraries
#include <qplaintextedit.h>

// Main lab task
void selection_sort(int* array, size_t size, QPlainTextEdit* const textEdit);

void random_fill_array(int* array, size_t size);

// Individual task
void cube_root_swap(double** matrix, size_t rows, size_t columns);

void random_fill_matrix(double** matrix, size_t rows, size_t columns);

#endif // ALGORITHMS_H
