#include <bits/stdc++.h>
using namespace std;

int power(int n,int m)
{
    if(m==1)
    {
        return n;
    }
    else
    {
        return n*power(n,m-1);
    }
}

int main()
{
    int x,y;

    cin>>x>>y;
    cout << power(x,y);

    return 0;
}