#include<bits/stdc++.h>
using namespace std;
double avg(int arr[],int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }
    return (arr[n - 1] + avg(arr, n - 1) * (n - 1)) / n;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout << "Avg = "<<avg(arr,n);

    return 0;
}

