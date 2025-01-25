#include <bits/stdc++.h>

using namespace std;

void logestIncreasingSubsequence(int arr[],int n)
{
   int arr2[n+1];
   for(int i =0;i<n;i++)
    arr2[i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                arr2[i] = max(arr2[i], arr2[j] + 1);
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr2[i] > max)
        {
            max = arr2[i];
        }
    }
    cout << max << endl;
}


int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr)/sizeof(arr[0]);
    logestIncreasingSubsequence(arr,n);
    return 0;
}




