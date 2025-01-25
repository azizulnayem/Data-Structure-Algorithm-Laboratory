//Problem 01
//MCM Algorithm Implementation

#include<iostream>
#include<climits>
using namespace std;
int MCM(int array[],int n){
        
        int matrix[n][n];
        int i,j,k,l,m;
        for(i=1; i<n; i++){
            matrix[i][i]=0;
        }
        for(l=2; l<n; l++){
            for(i=1; i<n-l+1; i++){
                j=i+l-1;
                matrix[i][j]=INT_MAX;
                for(k=i; k<=j-1; k++){
                    m=matrix[i][k]+matrix[k+1][j]+array[i-1]*array[k]*array[j];
                    if(m<matrix[i][j]){
                        matrix[i][j]=m;
                    }
                }
            }
        }
        return matrix[1][n-1];
}
int main(){
    int n;
    cout<<"Give the value of n: ";
    cin>>n;
    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    cout<<"Maximum Number of Multiplication: "<<MCM(array,n);
    return 0;
}