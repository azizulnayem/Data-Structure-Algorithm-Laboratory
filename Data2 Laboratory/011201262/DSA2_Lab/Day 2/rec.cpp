#include<bits/stdc++.h>
using namespace std;

float avg(int arr[],int length)
{
    float sum,avg1;

    if(length == 1)
    {
        sum =  arr[0];
    }

    else
    {
        float temp = avg(arr,length-1);

        sum = arr[length-1]+(length-1)*temp;
    }

    avg1 = sum/length;
    return avg1;
}

int main()
{
  int n;
  cin>>  n;

  int arr[n];

  for(int i=0;i<n;i++)
  {
     int k;
     cin >> k;
     arr[i] = k;
  }

  int length = sizeof(arr)/sizeof(arr[0]);

  avg(arr,length);
return 0;
}
