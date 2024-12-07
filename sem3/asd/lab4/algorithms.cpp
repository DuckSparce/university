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
        vec[i] = i;
    }

    std::random_shuffle(vec.begin(), vec.end());
}

void merge(std::vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int>& vec, int low, int high, QPlainTextEdit* const textEdit) {
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    merge_sort(vec, low, mid, textEdit);
    merge_sort(vec, mid + 1, high, textEdit);
    merge(vec, low, mid, high);

    array_output(vec, textEdit);
}

void mix_arrays(std::vector<int>& vec1, std::vector<int>& vec2, const size_t size, std::vector<int>& res) {
    for(size_t i = 0; i < size; i++) {
        if (vec1[i] % 2 == 0) {
            res.push_back(vec1[i]);
        }

        if (vec2[i] % 2 == 1) {
            res.push_back(vec2[i]);
        }
    }
}
