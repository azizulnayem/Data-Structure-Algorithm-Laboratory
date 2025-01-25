#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &number, int l, int m, int h)
{
    int cnt = 0;
    int j= m+1;

    for(int i=l; i<=m; i++)
    {
        while(j<=h && number[i]>(2*number[j]))
        {
            j++;
        }
        cnt += (j-(m+1));
    }
    vector<int> temp;
    int left = l, right = m+1;
    while(left<=m && right<=h)
    {
        if(number[left]<=number[right])
        {
            temp.push_back(number[left++]);
        }
        else
        {
            temp.push_back(number[right++]);
        }
    }
    while(left<=m)
    {
        temp.push_back(number[left++]);
    }
    while(right<=h)
    {
        temp.push_back(number[right++]);
    }
    for(int i=l; i<=h; i++)
    {
        number[i] = temp[i-l];
    }

    return cnt;
}

int margeSort(vector<int> &number, int l, int h)
{
    if(l>=h)
    {
        return 0;
    }
    int m = l+(h-l)/2;
    int inv = margeSort(number,l,m);
    inv += margeSort(number,m+1,h);
    inv += merge(number,l,m,h);
    return inv;

}

int reversePairs(vector<int> &number,int n)
{
    return margeSort(number,0,n-1);
}

int main()
{
    int n,a;
    n = 5;
    vector<int> number;
    for(int i=0; i<n; i++)
    {

        cin>>a;
        number.push_back(a);
    }
    cout<<reversePairs(number,n);
}
