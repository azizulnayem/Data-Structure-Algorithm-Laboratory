//14.Write a recursive program to check if a given string is a palindrome or not
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int palindrome_check(string s,int start,int end){
    if(end-start==1||start==end){
        return 1;
    }
    else{
        if(s[start]==s[end]){
            return palindrome_check(s,start+1,end-1);
        }
        else{
            return 0;
        }
    }
}
int main(){
    string s;
    getline(cin,s);
    int n=s.length();
    if(palindrome_check(s,0,n-1)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}