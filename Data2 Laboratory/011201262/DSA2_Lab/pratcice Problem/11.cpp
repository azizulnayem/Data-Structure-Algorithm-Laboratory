#include<bits/stdc++.h>
using namespace std;

int countOdd(int arr[], int n)
{
    if (n == 0)
        return 0;
    int count = countOdd(arr, n - 1);
    if (arr[n - 1] % 2 == 1)
        count++;
    return count;
}


int even (int arr[],int length)
{
    if (length == 0)
        return 0;
    int count = even(arr, length - 1);
    if (arr[length - 1] % 2 == 0)
        count++;
    return count;
}


int main()
{
    int arr[] = {1,2,3,4,5};
    cout <<"Find Odd Count : " <<countOdd(arr,5)<<endl;
    cout <<"Find Even Count : " <<even(arr,5)<<endl;
}

