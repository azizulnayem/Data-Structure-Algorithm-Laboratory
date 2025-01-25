#include <bits/stdc++.h>
using namespace std;

int min_element_array(int n,int min,int arr[])
{
    if(n>=0)
    {
        if(min>arr[n])
        {
            min = arr[n];
            min_element_array(n-1,min,arr);
        }
        else
            min_element_array(n-1,min,arr);
    }
    else
    {
        return min;
    }
}

int main()
{
    int n,min,arr[100];

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    min = arr[0];
    int m = n-1;
    cout << min_element_array(m,min,arr);

    return 0;
}