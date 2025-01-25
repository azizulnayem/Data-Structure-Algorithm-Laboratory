#include<bits/stdc++.h>
using namespace std;


void even(int n,int m)
{
   if(n>m)
    return;
   if(n%2==0)
    cout << n<< " ";
   even(n+1,m);
}

int main()
{
  int n,m;
  cin >> n>>m;

  cout << "Print even Number : ";

  even(n,m);

  cout << endl;


return 0;
}

