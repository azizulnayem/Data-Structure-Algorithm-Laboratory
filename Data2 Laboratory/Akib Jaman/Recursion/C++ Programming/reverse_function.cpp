#include<bits/stdc++.h>

using namespace std;

void func(int arr[],int n)
{
    int temp[100];

    for(int i=0; i<n; i++)
    {
        temp[i] = arr[n-1-i];
    }

    for(int i=0; i<n; i++)
    {
        cout<<temp[i]<<" ";
    }
}

int main()
{
    int n,arr[100];

    cout<<"Enter total number of element : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter "<<i+1<<" no element : ";
        cin>>arr[i];
    }

    cout<<"Old array : ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"New array : ";
    func(arr,n);


    return 0;
}
