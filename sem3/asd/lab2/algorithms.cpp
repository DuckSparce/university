#include "algorithms.h"

// CPP standard libraries
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

void shell_sort(int* const array, const size_t size, QPlainTextEdit* const textEdit) {
    array_output(array, size, textEdit);

    for (int h = size / 2; h > 0; h /= 2) {
        for (int i = h; i < size; i += 1) {
            int temp = array[i];
            int j;

            for (j = i; j >= h && array[j - h] > temp; j -= h) {
                array[j] = array[j - h];
            }

            array[j] = temp;
        }

        array_output(array, size, textEdit);
    }
}

void sort_student_list(std::vector<QString>& students, std::vector<double>& marks, size_t& size) {
    std::map<QString, double> map;

    for (size_t i = 0; i < size; i++) {
        map.insert({students[i], marks[i]});
    }

    students.clear();
    marks.clear();

    for (const auto & pair : map) {
        if (pair.second > 4) {
            students.emplace_back(pair.first);
            marks.emplace_back(pair.second);
        }
    }

    size = students.size();
}

/*
void sort_after_max(int* const array, const size_t size) {
    if (size < 2) {
        return;
    }

    size_t max = 0;

    for (size_t i = 1; i < size; i++) {
        if (array[i] >= array[max]) {
            max = i;
        }
    }

    shell_sort(array + max + 1, size - max - 1, nullptr);
}
*/
