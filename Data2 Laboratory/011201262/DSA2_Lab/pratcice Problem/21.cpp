#include<bits/stdc++.h>
using namespace std;
int binary(int arr[],int l, int h, int x)
{
    if(h>= l)
    {
        int mid = l+(h-l)/2;
        if(arr[mid]==x)
            return mid;

        if (arr[mid] > x)
            return binary(arr, l, mid - 1, x);
        return binary(arr,mid+1,h,x);

    }
        return -1;
}

int main()
{
    int n;
    cout << "How many data are want Entry ? : ";
         cin >> n;
    int arr[n];

    for(int i =0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);

    cout << "Print the array after the sort : "<<endl;

    for(auto m: arr)
    {
        cout << m << " ";
    }
    cout << endl;

    cout << "\nFind element : ";
    int x;
    cin >> x;


    int result =binary(arr,0,n,x);

    if(result == -1)
    {
        cout << "Element is not present in array" << endl;

    }

    else
        cout << "Element is present at index is :  " << result << endl;
    return 0;
}
