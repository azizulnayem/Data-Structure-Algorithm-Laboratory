#include<bits/stdc++.h>
using namespace std;
int Maximum(int arr[],int n)
{
    if (n == 1)
        return arr[0];
    int m = Maximum(arr, n - 1);
    return max(arr[n-1], m);
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
    cout << "Maximum = "<<Maximum(arr,n);

    return 0;
}
