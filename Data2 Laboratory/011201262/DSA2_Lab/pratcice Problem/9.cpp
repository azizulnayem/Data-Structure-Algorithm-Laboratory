#include<bits/stdc++.h>
using namespace std;
int Minimum(int arr[],int n)
{
    if (n == 1)
        return arr[0];
    int m = Minimum(arr, n - 1);
    return min(arr[n-1], m);
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
    cout << "Minimum = "<<Minimum(arr,n);

    return 0;
}

