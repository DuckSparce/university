#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// CPP standard libraries
#include <cstddef>

// QT libraries
#include <qplaintextedit.h>

void array_output(const int * const array, const size_t size, QPlainTextEdit* const textEdit);

void shell_sort(int* const array, const size_t size, QPlainTextEdit* const textEdit);

void random_fill_array(int* const array, const size_t& size);

void sort_student_list(std::vector<QString>& students, std::vector<double>& marks, size_t& size);

void sort_after_max(int* const array, const size_t size_t);

#endif // ALGORITHMS_H
