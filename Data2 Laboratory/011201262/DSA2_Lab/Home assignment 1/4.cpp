#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}


int main()
{
    int n;
    cin >>n;

    int a[n], sort_a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sort_a[i] = a[i];
    }

    int n1 = sizeof(sort_a)/sizeof(int);


    sort(sort_a,sort_a+n1);


   for(int j =0;j<n;j++)
   {

       int diff = binarySearch(sort_a, 0, n1-1, a[j]);

       int result = (n1-1)-diff-j;

       if(result <0 )
         cout << abs(result) << " Left" << endl;
       else if(result>0)
        cout << result << " Right"<<endl;
       else
        cout << "0" << endl;

   }


return 0;
}
