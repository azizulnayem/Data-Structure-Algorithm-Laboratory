//Quick Sort
//Implement Quick Sort using following pseudocode


#include <iostream>
using namespace std;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int pivot(int array[], int start, int end){
	int pi = array[end];
	int i = (start - 1); 

	for (int j = start; j <= end - 1; j++){
		if (array[j] < pi){
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[end]);
	return (i + 1);
}

void mainSort(int array[], int start, int end){
	if (start < end){
		int p = pivot(array, start, end);
		mainSort(array, start, p - 1);
		mainSort(array, p + 1, end);
	}
}

void print(int array[], int size){
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main(){
    int array[50],n;
    cout<<"Give n value: ";
    cin>>n;
    cout<<"Input: ";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    // int array[] = {}; 
    // int n = sizeof(array) / sizeof(array[0]); 
    mainSort(array,0,n-1);
    cout<<"Sorted array: ";
    print(array,n);

    return 0;
}