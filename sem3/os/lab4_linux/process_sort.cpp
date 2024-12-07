#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <unistd.h>

void insertionSort(std::vector<int>& arr) {
    int size = arr.size();
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << "Start of sorting.\n";
    std::vector<int> arr(200000);
    
    for (int i = 0; i < 200000; ++i) {
        arr[i] = std::rand();
    }

    insertionSort(arr);
    std::cout << "End of sorting.\n";
    
    return 0;
}
