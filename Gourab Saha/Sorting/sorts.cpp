#include<bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int>& arr);
void counting_sort(vector<int>& arr);

int main(){
    vector<int> arr{2, 3, 5, 1, 9 ,7};
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
    counting_sort(arr);
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
    return 0;
}

void insertion_sort(vector<int>& arr){
    for(int i=1; i<arr.size(); i++){
        int j = i;
        int temp;
        while (arr[j-1] > arr[j] && j>=0)
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

void counting_sort(vector<int>& arr){
    int max = -99999, min = 99999;
    for(int i=0; i<arr.size(); i++){
        if(max < arr[i])
            max = arr[i];

        if(min > arr[i])
            min = arr[i];
    }

    vector<int> counts(max-min+1, 0);
    for(int i=0; i<arr.size(); i++){
        counts[arr[i]-min]++;
    }

    int j = 0;
    for(int i=0; i<counts.size(); i++){
        while (counts[i] != 0)
        {
            arr[j++] = i+min;
            counts[i]--;
        } 
    }

}