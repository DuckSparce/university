#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QPlainTextEdit>
#include <algorithm>
#include <fstream>
#include <iostream>

void random_fill_array(std::vector<int>& array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    std::random_shuffle(array.begin(), array.end());
}

void write_array_to_file(const std::string &fileName, std::vector<int>& array) {
    std::ofstream outFile(fileName, std::ios_base::out);
    int size = array.size();

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return; // Exit the function if the file cannot be opened
    }

    for (int i = 0; i < size; ++i) {
        outFile << array[i] << " ";
    }

    outFile.close();
}

void selection_sort(std::vector<int>& array, const int size) {
    if (size == 0 || size == 1) {
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        int min = i;

        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }

        // int temp = array[i];
        // array[i] = array[min];
        // array[min] = temp;
        std::swap(array[i], array[min]);
    }
}

void shell_sort(std::vector<int>& array, const int size) {
    for (int h = size / 2; h > 0; h /= 2) {
        for (int i = h; i < size; i += 1) {
            int temp = array[i];
            int j;

            for (j = i; j >= h && array[j - h] > temp; j -= h) {
                array[j] = array[j - h];
            }

            array[j] = temp;
        }
    }
}

int partition(std::vector<int>& arr, int low, int high) {
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

void quick_sort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
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

void merge_sort(std::vector<int>& arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void counting_sort(std::vector<int>& arr, int size) {
    int max = 0;

    for (int i = 0; i < size; i++) {
        max = std::max(max, arr[i]);
    }

    std::vector<int> counts(max + 1, 0);

    for (int i = 0; i < size; i++) {
        (counts[arr[i]])++;
    }

    for (int i = 1; i <= max; i++) {
        counts[i] += counts[i - 1];
    }

    std::vector<int> vec_copy(arr);

    for (int i = size - 1; i >= 0; i--) {
        arr[counts[vec_copy[i]] - 1] = vec_copy[i];
        (counts[vec_copy[i]])--;
    }
}

#endif // ALGORITHMS_H
