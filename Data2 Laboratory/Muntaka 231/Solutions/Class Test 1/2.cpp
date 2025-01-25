#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fib(n-1) + fib(n-2);
}

int power(int x, int y)
{
    if(y == 0) return 1;

    int a = pow(x, y/2);

    if ( y%2 == 0)
        return a*a;
    else
        return x*a*a;
}

int main(){
    int N,M;
    cin>>N>>M;
    int x = fib(N);
    int y = fib(M);
    cout<<power(x,y)<<endl;
}