#include <iostream>
#include <vector>
#include <algorithm>

int findMode(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end()); // Sort the array in ascending order

    int mode = arr[0]; // Initialize mode to the first element
    int maxFrequency = 1; // Initialize the maximum frequency to 1
    int currentFrequency = 1; // Frequency of the current element
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentFrequency++;
        } else {
            currentFrequency = 1;
        }

        if (currentFrequency > maxFrequency) {
            maxFrequency = currentFrequency;
            mode = arr[i];
        }
    }

    return mode;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int mode = findMode(arr);
    std::cout << "Mode: " << mode << std::endl;

    return 0;
}

