#include<bits/stdc++.h>
#define max_value 100
using namespace std;

int maximum(int arr[][max_value],int n,int m,int i,int j)
{
    if (i == n - 1 && j == m - 1)
        return arr[i][j];
    if (j == m - 1)
        return max(arr[i][j], maximum(arr, n, m, i + 1, 0));
    return max(arr[i][j], maximum(arr, n, m, i, j + 1));
}

int main()
{
    int arr[max_value][max_value];
    int n,m;

    cin >>n>>m;


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout <<"Maximum Element From 2D Array : "<< maximum(arr,n,m,0,0)<<endl;

    return 0;
}
