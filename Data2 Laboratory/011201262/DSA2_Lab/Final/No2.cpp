#include<bits/stdc++.h>
using namespace std;


void t(int arr[],int n)
{
    int sum =0;
    if(n==1)
    {
        sum =0;
    }
    else
    {
        for(int i =1 ; i<n; i++)
        {
            if(arr[i]<=arr[i-1])
            {
                sum += arr[i-1]-arr[i]+1;
                arr[i] = arr[i-1]+1;
            }
        }

    }

    cout << sum <<endl;
}

int main()
{
    int arr[] = {1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    t(arr,n);

    return 0;
}



