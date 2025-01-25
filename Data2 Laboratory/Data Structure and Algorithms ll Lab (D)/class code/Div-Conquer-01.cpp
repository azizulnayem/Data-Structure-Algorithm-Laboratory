#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void mergeSort(int A[],int lb, int ub);
void MERGE(int A[],int lb,int ub,int mid);

int main()
{
    int arr[]= {1,4,3,100,10,2,11,34,35};
    int length=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,length-1);
    for(int i=0; i<length; i++)
    {
        cout<< arr[i] << " ";
    }
    return 0;
}

void mergeSort(int A[],int lb, int ub)
{
    if (lb<ub)
    {
        int mid=(lb+ub)/2;
        mergeSort(A, lb, mid);
        mergeSort(A, mid+1, ub);
        MERGE(A,lb,ub,mid);
    }
    return;
}

void MERGE(int A[],int lb,int ub,int mid)
{
    int length = (ub-lb)+1;
    int b[length];
    int p1=lb;
    int p2=mid+1;
    int k=0;

    while (p1<=mid && p2<=ub)
    {
        if(A[p1]<A[p2])
        {
            b[k]= A[p1];
            p1++;
        }
        else
        {
            b[k]= A[p2];

            p2++;
        }
        k++;
    }
    if(p1>mid)
    {
        while(p2<=ub )
        {
            b[k]= A[p2];
            k++;
            p2++;
        }
    }

    if(p2>ub)
    {
        while (p1<=mid)
        {
            b[k]= A[p1];
            k++;
            p1++;
        }
    }
    k=0;
    for(int i=lb; i<=ub; i++)
    {
        A[i]=b[k];
        k++;
    }
}

