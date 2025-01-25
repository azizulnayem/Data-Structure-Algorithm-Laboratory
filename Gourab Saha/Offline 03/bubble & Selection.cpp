#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template<typename T>
void selectionSort(T arr[], int n, vector<int>& swaps) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps.push_back(i);
            swaps.push_back(minIndex);
        }
    }
}

template<typename T>
void bubbleSort(T arr[], int n, vector<int>& swaps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps.push_back(j);
                swaps.push_back(j + 1);
            }
        }
    }
}

template<typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int k;
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    inputFile >> k;
    for (int t = 0; t < k; t++) {
        int n;
        inputFile >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            inputFile >> arr[i];
        }
        vector<int> swaps;

        // Sort using selection sort
        selectionSort(arr, n, swaps);
        outputFile << "Selection sort swaps: " << swaps.size() / 2 << endl;
        outputFile << "Selection sort output: ";
        printArray(arr, n);

        // Sort using bubble sort
//        bubbleSort(arr, n, swaps);
//        outputFile << "Bubble sort swaps: " << swaps.size() / 2 << endl;
//        outputFile << "sort output: ";
//        printArray(arr, n);

        inputFile.close();
        outputFile.close();
        return 0;

}
}
