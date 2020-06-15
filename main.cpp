#include <iostream>

int binarySearch(const int *array, int size, int target);

void selectionSort(int *array, int size);

int main() {
    int array[128];
    int length = sizeof(array) / sizeof(int);
    for (int i = 0; i < length; i++) {
        array[i] = i + 1;
    }
    binarySearch(array, length, 128);

    int array2[5] = {3, 2, 5, 4, 1};
    length = sizeof(array2) / sizeof(int);
    selectionSort(array2, length);
    std::cout << "array2: ";
    for (int i = 0; i < length; ++i) {
        std::cout << array2[i] << ", ";
    }
    std::cout << "\b\b " << std::endl;

    return 0;
}

// O(log n)
int binarySearch(const int *array, int size, int target) {
    int low = 0, high = size - 1;
    int mid = 0, temp = 0, count = 0;
    bool isExists = false;
    while (low <= high) {
        count++;
        mid = (high + low) / 2;
        temp = *(array + mid);
        if (temp == target) {
            isExists = true;
            break;
        } else if (temp < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << "count: " << count;
    if (isExists) {
        std::cout << ", target exists in " << mid << std::endl;
    } else {
        std::cout << ", target does not exist" << std::endl;
    }
    return 0;
}

// O(n^2) https://www.runoob.com/w3cnote/selection-sort.html
void selectionSort(int *array, int size) {
    int minIndex, temp;
    for (int i = 0; i < size - 1; ++i) { // i < size - 1：当 i 为最后一个元素时，不再进入循环，少一次检查
        minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (*(array + i) > *(array + j)) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = *(array + i);
            *(array + i) = *(array + minIndex);
            *(array + minIndex) = temp;
        }
    }
}


