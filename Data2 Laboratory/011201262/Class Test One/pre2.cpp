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
  int N, M;

  cin >> N >> M;
  int x = fib(N);
  int y = fib(M);



  cout << N << "th Fibonacci Is : "<< x <<endl;
  cout << M << "th Fibonacci Is : "<< y <<endl;

  cout << pow(x,y) << endl;

return 0;
}

