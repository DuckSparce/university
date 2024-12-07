#include "algorithms.h"

// CPP standard libraries
#include <cstdlib>

void array_output(const  std::vector<int>& vec, QPlainTextEdit* const textEdit) {
    if (textEdit != nullptr) {
        for (size_t i = 0; i < vec.size(); i++) {
            textEdit->insertPlainText(QString::number(vec[i]) + ' ');
        }

        textEdit->insertPlainText(QString('\n'));
    }
}

void random_fill_array(std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = std::rand() % 4;
    }
}

void counting_sort(std::vector<int>& vec, QPlainTextEdit* const textEdit) {
    textEdit->insertPlainText("Initial array:\n");
    array_output(vec, textEdit);

    size_t size = vec.size();
    int max = 0;

    for (size_t i = 0; i < size; i++) {
        max = std::max(max, vec[i]);
    }

    std::vector<int> counts(max + 1, 0);

    textEdit->insertPlainText("Counts array:\n");

    for (size_t i = 0; i < size; i++) {
        (counts[vec[i]])++;
    }

    array_output(counts, textEdit);

    for (size_t i = 1; i <= max; i++) {
        counts[i] += counts[i - 1];
    }

    array_output(counts, textEdit);

    std::vector<int> vec_copy(vec);

    for (int i = size - 1; i >= 0; i--) {
        vec[counts[vec_copy[i]] - 1] = vec_copy[i];

        (counts[vec_copy[i]])--;
    }

    textEdit->insertPlainText("Result array:\n");
    array_output(vec, textEdit);
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

