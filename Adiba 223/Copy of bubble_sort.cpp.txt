#include <bits/stdc++.h>
using namespace std;
void printArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        cout << array[i] << endl;
}

void bubbleSort(int *array, int n)
{
    bool swapped = true;
    int j = 0;
    int temp;

    while (swapped==true)
    {
        swapped = false;
        j++;
        cout<<"step no : "<< j << endl;

        for (int i = 0; i < n - j; ++i)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
          cout<<"swapped :" <<swapped<< endl;
    }
}

int main()
{
    int array[] = {-2,45,0,11,-9};
    int n = sizeof(array)/sizeof(array[0]);
    //array_input


    cout << "Before Bubble Sort :" << endl;
    printArray(array, n);

    bubbleSort(array, n);

    cout << "After Bubble Sort :" <<endl;
    printArray(array, n);
    return (0);
}
