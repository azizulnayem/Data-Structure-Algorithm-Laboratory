///Problem 02

#include<bits/stdc++.h>
using namespace std;
void minWord(string &str,string &minword, string &maxword){
        int len=str.length();
        int si = 0, ei = 0;
        int min_length = len,
            min_start_index = 0,
            max_length = 0,
            max_start_index = 0;

        while(ei<=len){
            if(ei<len && str[ei]!=' '){//check string is not empty
                ei++;
            }
            else{         //current word length
                int curr_length=ei-si;
                if (curr_length < min_length){
                min_length = curr_length;
                min_start_index = si;
            }

            if (curr_length > max_length){
                max_length = curr_length;
                max_start_index = si;
            }
            ei++;
            si = ei;
            }
        }
        minword = str.substr(min_start_index, min_length);//store minimum length word
        maxword = str.substr(max_start_index, max_length);//store maximum length word
}
int main(){

    string str="happy roung";
    string minword,maxword;
    minWord(str,minword,maxword);
    cout<<minword<<endl;

    return 0;
}
