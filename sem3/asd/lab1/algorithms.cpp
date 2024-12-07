#include "algorithms.h"

// CPP standard libraries
#include <algorithm>
#include <cstdlib>
#include <utility>

void selection_sort(int* array, const size_t size, QPlainTextEdit* const textEdit) {
    if (size == 0 || size == 1) {
        return;
    }

    // Output the array
    if (textEdit != nullptr) {
        for (size_t i = 0; i < size; i++) {
            textEdit->insertPlainText(QString::number(array[i]) + ' ');
        }

        textEdit->insertPlainText(QString('\n'));
    }

    for (size_t i = 0; i < size - 1; i++) {
        size_t min = i;

        for (size_t j = i + 1; j < size; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }

        std::swap(array[i], array[min]);

        // Output the array
        if (textEdit != nullptr) {
            for (size_t i = 0; i < size; i++) {
                textEdit->insertPlainText(QString::number(array[i]) + ' ');
            }

            textEdit->insertPlainText(QString('\n'));
        }
    }
}

void random_fill_array(int* array, const size_t size) {
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    std::random_shuffle(array, &(array[size]));
}

void random_fill_matrix(double** matrix, size_t rows, size_t columns) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            matrix[i][j] = std::rand() % 1000;
        }
    }
}

void cube_root_swap(double **matrix, size_t rows, size_t columns) {
    if (columns == 0 || rows == 0) {
        throw std::length_error("The matrix size can't be zero");
    }

    // Find max and set it to cbrt(x)
    for (size_t i = 0; i < rows; i++) {
        size_t max = 0;

        for (size_t j = 1; j < columns; j++) {
            if (matrix[i][max] < matrix[i][j]) {
                max = j;
            }
        }

        matrix[i][max] = cbrt(matrix[i][max]);
    }

    // Sort the matrix
    for (size_t i = 0; i < rows - 1; i++) {
        size_t min = i;

        for (size_t j = i + 1; j < rows; j++) {
            if (matrix[j][0] < matrix[min][0]) {
                min = j;
            }
        }

        std::swap(matrix[i], matrix[min]);
    }
}
