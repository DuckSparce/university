#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// CPP standard libraries
#include <vector>

// QT libraries
#include <qplaintextedit.h>

void array_output(const std::vector<int>& vec, QPlainTextEdit* const textEdit);

void merge_sort(std::vector<int>& vec, int low, int high, QPlainTextEdit* const textEdit);

void random_fill_array(std::vector<int>& vec);

void mix_arrays(std::vector<int>& vec1, std::vector<int>& vec2, const size_t size, std::vector<int>& res);

#endif // ALGORITHMS_H
