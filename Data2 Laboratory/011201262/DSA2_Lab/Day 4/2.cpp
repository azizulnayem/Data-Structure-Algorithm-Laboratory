#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fib(n-1)+fib(n-2);
}

int pow(int j,int k)
{
    if(k==0)
        return 1;
    if(k==1)
    {
        return j;
    }
    return j*pow(j,k-1);
}

int main()
{
    int n,m;
    cin >> n>> m;

    int j = fib(n);
    int k = fib(m);

    cout << "Power "<<j<<"^"<<k<<" is : "<<pow(j,k)<<endl;


    return 0;
}
