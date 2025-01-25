#include<bits/stdc++.h>
using namespace std;

bool blanceBracket(string s, int i, int j)
{
    if (j < 0)
        return false;
    if (i == s.length())
        return j == 0;
    if (s[i] == '(')
        return blanceBracket(s, i+1, j+1);
    else if (s[i] == ')')
        return blanceBracket(s, i+1, j-1);
    else
        return false;
}

int main()
{
    string s;
    cin >> s;
    if (blanceBracket(s, 0, 0))
        cout << "YES"<<endl;
    else
        cout << "NO"<<endl;
    return 0;
}
