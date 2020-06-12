#include <iostream>

int binarySearch(const int *array, int size, int target);

int main() {
    int array[256];

    for (int i = 0; i < 256; i++) {
        array[i] = i + 1;
    }

    binarySearch(array, sizeof(array) / sizeof(int), 256);

    return 0;
}

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


