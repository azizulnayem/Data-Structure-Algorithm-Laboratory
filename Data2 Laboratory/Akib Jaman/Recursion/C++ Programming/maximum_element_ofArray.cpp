#include <bits/stdc++.h>
using namespace std;

int max_element_array(int n,int max,int arr[])
{
    if(n>=0)
    {
        if(max<arr[n])
        {
            max = arr[n];
            max_element_array(n-1,max,arr);
        }
        else
            max_element_array(n-1,max,arr);
    }
    else
    {
        return max;
    }
}

int main()
{
    int n,max=0,arr[100];

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int m = n-1;
    cout << max_element_array(m,max,arr);

    return 0;
}