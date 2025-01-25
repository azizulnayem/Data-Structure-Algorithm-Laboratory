#include<bits/stdc++.h>
using namespace std;

void mergeArray(int a[], int left, int middle, int right)
{
    int n1 = middle-left+1;
    int n2 = right-middle;
    int left_array[n1], right_array[n2];

    for(int i=0; i<n1; i++) left_array[i] = a[left+i];
    for(int i=0; i<n2; i++) right_array[i] = a[middle+1+i];

    int i=0, j=0, k=left;

    while(i<n1 && j<n2)
    {
        if(left_array[i]<=right_array[j])
        {
            a[k] = left_array[i];
            i++;
        }
        else
        {
            a[k] = right_array[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        a[k] = left_array[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        a[k] = right_array[j];
        j++;
        k++;
    }

}

void mergeSort(int a[], int left, int right)
{
    if(left<right)
    {
        int middle = left + (right-left)/2;
        mergeSort(a, left, middle);
        mergeSort(a, middle+1, right);

        mergeArray(a, left, middle, right);
    }
}
int main()
{
    int n, k;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>k;

    mergeSort(a,0,n-1);

    cout<<a[n-k]<<endl;
    return 0;
}
