#include<bits/stdc++.h>
using namespace std;


void rev(int arr[],int n)
{
   if(n==0)
        return ;
   cout<<arr[n-1]<<" ";
   rev(arr,n-1);
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for(int i =0;i<n;i++)
  {
      cin >> arr[i];
  }
  cout << "Reverse Order : ";

  rev(arr,n);

  cout << endl;


return 0;
}
