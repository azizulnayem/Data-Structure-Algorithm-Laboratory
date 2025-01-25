#include<bits/stdc++.h>
using namespace std;

bool balancedParentheses(string str,int i,int cnt){
    if(str[i]=='\0')
        return cnt==0;
    if(str[i]=='(')
        cnt++;
    else
        cnt--;
    if(cnt<0)
        return false;
    return balancedParentheses(str,i+1,cnt);
}
int main(){
    string str;
    cin>>str;
    if(balancedParentheses(str,0,0))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}