//Kth Largest Element in an array line

#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

//return correct index of any random chosen pivot
int helperFnc(int &l,int &r, vector<int> &array){
    int rnd = (rand() % (r - l + 1)) + l;
    swap(array[rnd] , array[r]);
    int idx = l;
    for(int i = l ; i < r ; i++)
    {
        if(array[i] < array[r])
        {
            swap(array[i] , array[idx]);
            idx++;
        }
    }
    swap(array[idx] , array[r]);
    return idx;
}
//return n-k th smallest element
int quickSort(int l,int r,int k, vector<int> &array){
    while(l <= r)
    {
        int pivotIdx = helperFnc(l , r , array);
        if(pivotIdx == k)
            return array[pivotIdx];
        if(pivotIdx < k)
            l = pivotIdx + 1;
        else
            r = pivotIdx - 1;
    }
    return -1;
}
int kthLargest(vector<int> &array, int &k){
    int n=array.size();
    return quickSort(0,n-1,n-k,array);
}
int main(){
    vector <int> array = {3,2,3,1,2,4,5,5,6};
     int k = 4;
    
    cout <<"Output: "<<kthLargest(array , k) <<endl;
}