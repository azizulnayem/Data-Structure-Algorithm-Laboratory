#include<bits/stdc++.h>
using namespace std;
bool isSubSum(int arr[],int sum,int n)
{
    bool sub[n+1][sum+1];

    for (int i = 0; i <= n; i++)
        sub[i][0] = true;
    for (int i = 1; i <= sum; i++)
        sub[0][i] = false;

    for(int i=1; i<= n ;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]>j)
                sub[i][j] = sub[i-1][j];
            if(arr[i-1]<=j)
                sub[i][j] = sub[i-1][j]||sub[i-1][j-arr[i-1]];
        }
    }
    return sub[n][sum];
}
int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 30;
     int n = sizeof(arr)/sizeof(arr[0]);

    if(isSubSum(arr,sum,n))
        cout << "True\n";
    else
        cout <<"False\n";

    return 0;
}
