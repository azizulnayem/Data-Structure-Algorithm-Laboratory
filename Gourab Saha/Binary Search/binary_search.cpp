#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> arr, int left, int right, int searchElement){
    int mid = (left+right) / 2;

    if (arr[mid] == searchElement) return mid;
    else if (left == right) return -1;
    else if (searchElement < arr[mid])
        return binarySearch(arr, left, mid-1, searchElement);
    else 
        return binarySearch(arr, mid+1, right, searchElement);
    
}

int main(){
    vector<int> arr{10, 15, 20, 25, 30, 35};
    int searchElement = 21;

    int idx = binarySearch(arr, 0, arr.size()-1, searchElement);
    if (idx != -1)
        cout << "Element exists at " << idx << endl;
    else
        cout << "Element does not exist" << endl;
}