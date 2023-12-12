#include <iostream>

using namespace std;

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
        swap(arr[i], arr[minIndex]);
    }
}

template <typename T>
void displayArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int intSize = 5;
    const int floatSize = 5;

    int intArray[intSize] = {64, 25, 12, 22, 11};
    float floatArray[floatSize] = {64.5, 25.3, 12.7, 22.1, 11.9};

    cout << "Original Integer Array: ";
    displayArray(intArray, intSize);

    // Sorting integer array using the selectionSort template
    selectionSort(intArray, intSize);

    cout << "Sorted Integer Array: ";
    displayArray(intArray, intSize);

    cout << "\nOriginal Float Array: ";
    displayArray(floatArray, floatSize);

    // Sorting float array using the selectionSort template
    selectionSort(floatArray, floatSize);

    cout << "Sorted Float Array: ";
    displayArray(floatArray, floatSize);

    return 0;
}


/tmp/8QqfopyExh.o
Original Integer Array: 64 25 12 22 11 
Sorted Integer Array: 11 12 22 25 64 

Original Float Array: 64.5 25.3 12.7 22.1 11.9 
Sorted Float Array: 11.9 12.7 22.1 25.3 64.5
