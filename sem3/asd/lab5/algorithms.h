#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// CPP standard libraries
#include <vector>

// QT libraries
#include <qplaintextedit.h>

void array_output(const std::vector<int>& vec, QPlainTextEdit* const textEdit);

void counting_sort(std::vector<int>& vec, QPlainTextEdit* const textEdit);

void random_fill_array(std::vector<int>& vec);

void random_fill_matrix(double** matrix, size_t rows, size_t columns);

void cube_root_swap(double** matrix, size_t rows, size_t columns);

#endif // ALGORITHMS_H
