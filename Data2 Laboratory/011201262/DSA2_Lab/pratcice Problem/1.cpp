#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if(n==0||n==1)
    {
        return 1;
    }

    return n*factorial(n-1);
}

int main()
{
   int n;
   scanf("%d", &n);
   printf("the factorial is %d",factorial(n));

   /*cin >> n;
   cout << n<<"the Factorial is : "<<factorial(n)<<endl;*/

return 0;
}
