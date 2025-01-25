#include<bits/stdc++.h>
using namespace std;
void Calc_LPS(char *pattern, int m, int *LPS){
    int len=0;
    int i=1;
    LPS[0]=0;
    while(i<m){
        if(pattern[len]==pattern[i]){
            LPS[i]=len+1;
            i++;
        }else{
            if(len!=0){
                len=LPS[len-1];
            }else{
                LPS[i]=0;
                i++;
            }
        }
    }
}
void KMP(char *text, char *pattern){
    int n=strlen(text);
    int m=strlen(pattern);
    int LPS[m];
    Calc_LPS(pattern,m,LPS);

    for(int i=0; i<m; i++){
        cout<<LPS[i]<<"\t";
    }
    int i=0;
    int j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        else(j!=0){
            j=
        }
        if(j==m){
            cout<<"Match found"<<i-j<<" th index"<<;
            j=LPS[j-1];
        }
    }
}
int main(){
    char text[]="ABABCABCABABABD";
    char pattern[]="ABABD";
    KMP(text,pattern);
    return 0;
}