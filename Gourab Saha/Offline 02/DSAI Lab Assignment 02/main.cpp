
/*
 *  Name: Rabinul Islam
 *  ID: 011213010
 *  Course Name: Data Structure And Algorithms Lab
 *  Course Code: CSE 2216
 *  Section: B
 *  Topic: Assignment 02
 */

#include "stdlibs.h"
#include "DoubleList.cpp"
using namespace std;

template<class T>
class BinarySearch : public DoubleList<T> {
public:
    int search(int min, int max, T search) {
        int mid = (max + min) / 2;

        if(this->at(mid) == search) return mid;
        else if(min == max) return -1;
        else if(this->at(mid) < search) return this->search(mid + 1, max, search);
        else return this->search(min, mid - 1, search);
    }
};

int main() {
    // Path to the text file
    const string fileName = "C:/absolute_path_to_the_file/file.txt";

    ifstream *is = new ifstream(fileName, ios::in);
    if(is == nullptr || is->fail()) {
        cerr << "Failed to open the input file." << endl;
        return -1;
    }

    int k, n;
    // Change data type for different inputs of in, search and BinarySearch
    double in, search;
    BinarySearch<double> *list = new BinarySearch<double>();

    *is >> k;
    for(int i = 0; i < k; i++) {
        *is >> n;
        while(n > 0) {
            *is >> in;
            list->pushBack(in);
            n--;
        }
        *is >> search;
        // Search element and print the result
        cout << list->search(0, list->getLength()-1, search) << endl;
        list->clear();      // clear the list for new inputs
    }

    list->clear();
    return 0;
}
