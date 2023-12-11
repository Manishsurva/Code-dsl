#include <iostream>

template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 5;
    float floatArray[size] = {3.2, 1.7, 2.5, 4.8, 1.1};

    std::cout << "Original array: ";
    printArray(floatArray, size);

    selectionSort(floatArray, size);

    std::cout << "Sorted array: ";
    printArray(floatArray, size);

    return 0;
}
