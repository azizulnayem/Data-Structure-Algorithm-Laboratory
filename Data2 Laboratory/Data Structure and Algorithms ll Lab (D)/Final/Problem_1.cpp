///Problem 01

#include<bits/stdc++.h>
using namespace std;
void violation(int array[],int n){

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(array[i]>array[j]){
                    int temp=array[i];
                    array[i]=array[j];
                    array[j]=temp;
                }
            }
        }
        cout<<"Violation Fixed : ";
        for(int i=0; i<n; i++){
            cout<<array[i]<<"  ";
        }
        cout<<endl;
}
int main(){
    int n;
    cout<<"Value of n: ";
    cin>>n;
    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    violation(array,n);
    return 0;
}
