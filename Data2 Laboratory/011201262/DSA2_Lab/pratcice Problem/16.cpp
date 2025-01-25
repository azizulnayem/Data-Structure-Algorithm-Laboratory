#include<bits/stdc++.h>
#define max_value 100
using namespace std;
bool isPrime(int n)
{
    if(n<=1)
        return false;
    for(int i = 2;i<=sqrt(n);i++)
    {
        if(n%i == 0)
        {
            return false ;
        }
    }

    return true;
}

int countPrime(int arr[][max_value],int n,int m,int i ,int j)
{
    if(i == n)
        return 0;
    if(j == m)
        return countPrime(arr,n,m,i+1,0);
    return isPrime(arr[i][j])+countPrime(arr,n,m,i,j+1);
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

    cout << "Total prime number is : "<< countPrime(arr,n,m,0,0)<<endl;

    return 0;
}

