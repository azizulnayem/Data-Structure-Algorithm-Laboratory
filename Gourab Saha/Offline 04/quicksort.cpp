#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function to partition the array and return the index of the pivot element
template<typename T>
int partition(vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

// Function to perform Quick Sort
template<typename T>
void quickSort(vector<T>& arr, int low, int high, int depth) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1, depth+1);
        quickSort(arr, pi+1, high, depth+1);
    }
}

int main() {
    int k;
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt", ios::app);

    // Read the number of test cases from the input file
    inputFile >> k;

    for (int i = 0; i < k; i++) {
        int n;
        inputFile >> n;

        // Read the input array
        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            inputFile >> arr[j];
        }

        // Perform Quick Sort and measure the depth of recursion
        int depth = 0;
        quickSort(arr, 0, n-1, depth);

        // Write the sorted array to the output file
        for (int j = 0; j < n; j++) {
            outputFile << arr[j] << " ";
        }
        outputFile << endl;

        // Write the depth of recursion to the console
        cout << "Depth of recursion for test case " << i+1 << ": " << depth << endl;
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    return 0;
}
