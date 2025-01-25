#include <bits/stdc++.h>
using namespace std;

int sum_array(int n,int sum,int arr[])
{
    
    if(n>=0)
    {
        sum += arr[n];
        sum_array(n-1,sum,arr);
    }
    else
    {
        return sum;
    }
}

int main()
{
    int n,sum=0,arr[100];

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int m = n-1;
    cout << sum_array(m,sum,arr);

    return 0;
}