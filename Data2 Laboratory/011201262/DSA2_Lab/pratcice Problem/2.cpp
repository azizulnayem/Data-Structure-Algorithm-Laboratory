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

int main()
{
  int n;
  int a = 10;
  cin >> n;

  cout << n << "th Fibonacci Is : "<<fib(n)<<endl;

return 0;
}
