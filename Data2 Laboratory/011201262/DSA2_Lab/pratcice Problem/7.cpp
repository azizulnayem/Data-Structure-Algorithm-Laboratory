#include<bits/stdc++.h>
using namespace std;
int productOfArray(int arr[],int n)
{
    if(n==0)
    {
        return 1;
    }
    return arr[n-1]*productOfArray(arr,n-1);
}

int main()
{
  int n;
  cin >> n;
  int arr[n];

  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
  }
   cout << "product = "<<productOfArray(arr,n);
return 0;
}

