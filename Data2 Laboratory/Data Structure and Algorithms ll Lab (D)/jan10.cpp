//LCS
//finding out LCS sequence value
#include<iostream>
#include<cstring>
using namespace std;
void LCS(char *X,char *Y,int lenx,int leny){
    int L[lenx+1][leny+1];
    for(int i=0; i<=lenx; i++){
        for(int j=0; j<=leny; j++){
            if(i==0 || j==0){
                L[i][j]=0;
               
            } else if(X[i]==Y[j]){
                    L[i][j]=L[i-1][j-1]+1;
                }
                else{
                        L[i][j]=max(L[i][j-1],L[i-1][j]);
                }
        }
    }
    cout<<"Length of the LCS: "<<L[lenx][leny]<<endl;
    
    int len_LCS=L[lenx][leny];
    char LCS[len_LCS+1];
    LCS[len_LCS]='\0';
    int index=len_LCS;
    int i=lenx;
    int j=leny;
    while (i>0 && j>0){
        if(X[i-1]==Y[j-1]){
        LCS[index-1]=X[i-1];
        index--;
        i--;
        j--;
        }
        else if (L[i-1][j]>L[i][j-1]){
            i--;
        }
        else if(L[i-1][j]==L[i][j-1]){
            
        }
        else{
            j--;
        }
        
        
    }
    cout<<"LCS: "<<LCS<<endl;
}
int main(){
    char X[]="ABCBDAB";
    char Y[]="BDCABA";
    int m=strlen(X);
    int n=strlen(Y);
    LCS(X,Y,m,n);
    return 0;
}


