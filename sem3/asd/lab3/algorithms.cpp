#include "algorithms.h"

// CPP standard libraries
#include <utility>
#include <cstdlib>

void array_output(const int * const array, const size_t size, QPlainTextEdit* const textEdit) {
    if (textEdit != nullptr) {
        for (size_t i = 0; i < size; i++) {
            textEdit->insertPlainText(QString::number(array[i]) + ' ');
        }

        textEdit->insertPlainText(QString('\n'));
    }
}

void random_fill_array(int* const array, const size_t& size) {
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    std::random_shuffle(array, &(array[size]));
}

int partition(int arr[], int low, int high) {
    int pivotIndex = low + (high - low) / 2;
    int pivot = arr[pivotIndex];

    std::swap(arr[pivotIndex], arr[high]);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(int* arr, size_t size, int low, int high, QPlainTextEdit* const textEdit) {
    if (low < high) {
        array_output(arr, size, textEdit);
        int pi = partition(arr, low, high);

        quick_sort(arr, size, low, pi - 1, textEdit);
        quick_sort(arr, size, pi + 1, high, textEdit);
    }
}

void sort_between_negatives(int* const array, const size_t size) {
    size_t first = size;
    size_t last = size;

    for (size_t i = 0; i < size; i++) {
        if (array[i] < 0) {
            if (first == size) {
                first = i;
            }

            last = i;
        }
    }

    quick_sort(array, size, first + 1, last - 1, nullptr);
}
