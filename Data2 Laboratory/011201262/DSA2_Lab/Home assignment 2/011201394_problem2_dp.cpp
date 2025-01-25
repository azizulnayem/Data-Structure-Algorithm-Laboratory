#include<bits/stdc++.h>
using namespace std;

int LCS(string x,string y )
{
    int m = x.size();
    int n = y.size();

    int arr[m+1][n+1];

    for(int i =0;i<=m;i++)
    {
        for(int j =0;j<=n;j++)
        {
            if(i==0||j==0)
                arr[i][j] = 0;
            else if(x[i-1]==y[j-1])
                arr[i][j] = arr[i-1][j-1]+1;
            else
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
        }
    }

    return arr[m][n];
}

int main()
{

    string x,y;
    cout << "Input x : ";
    cin >> x;

    cout << "\nInput y : ";
    cin >> y;

    cout << "\nLength: "<<LCS(x,y)<<endl;

return 0;
}
