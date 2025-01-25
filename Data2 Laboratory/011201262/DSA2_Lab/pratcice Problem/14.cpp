#include <bits/stdc++.h>
using namespace std;
int Palindrome(char str[], int f, int l)
{
    if (f < l + 1)
    {
        f++;
        l--;
        return Palindrome(str, f, l);
    }

    if (f == l)
    {
        return 1;
    }
    if (str[f] != str[l])
    {
        return 0;
    }
    return 1;
}
int main()
{

    char Str[] = "mam";
    int result;
    int length = strlen(Str);
    if (length == 0)
    {
        result=1;
    }

    else
    {
        result=Palindrome(Str, 0, length - 1);
    }
    if (result==1)
    {
        cout << "Given string is palindrome.";
    }
    else
    {
        cout << "Given string is not a palindrome.";
    }
    return 0;
}
