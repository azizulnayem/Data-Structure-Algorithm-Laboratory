#include<bits/stdc++.h>
using namespace std;

void merge(int *number, int l, int m, int r)
{
    int i, j, k, nl, nr;

    nl = m-l+1;
    nr = r-m;
    int larr[nl], rarr[nr];

    for(i = 0; i<nl; i++)
    {
        larr[i] = number[l+i];
    }

    for(j = 0; j<nr; j++)
    {
        rarr[j] = number[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < nl && j<nr)
    {
        if(larr[i] >= rarr[j])
        {
            number[k] = larr[i];
            i++;
        }
        else
        {
            number[k] = rarr[j];
            j++;
        }
        k++;
    }

    while(i<nl)
    {
        number[k] = larr[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        number[k] = rarr[j];
        j++;
        k++;
    }
}
void mergeSort(int *number, int l, int r)
{
    int m,a,b,c,sum=0;
    if(l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(number, l, m);
        mergeSort(number, m+1, r);
        merge(number, l, m, r);
    }
}

int main()
{
    int n,number[100],k;
    n = 6;
    for(int i=0; i<n; i++)
    {
        cin>>number[i];
    }
    mergeSort(number,0,n-1);
    cout<<"k = ";
    cin>>k;
    cout<<number[k-1];
}
