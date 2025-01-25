#include<bits/stdc++.h>
using namespace std;

///3 flower flow flight

string longestCommonPrefix(string ar[], int n)
{
    if (n == 0)
        return "EMPTY";
    if (n == 1)
        return ar[0];
    sort(ar, ar + n);

    int en = min(ar[0].size(),ar[n - 1].size());

    string first = ar[0], last = ar[n - 1];

    int i = 0;
    while (i < en && first[i] == last[i])
        i++;
    string pre = first.substr(0, i);
    return pre;
}


int main()
{
    int n;
    cin >>n;
    string ar[n];
    for(int i=0; i<n; i++)
    {
        string a;
        cin >> a;
        ar[i] = a;
    }
    cout << "Output IS:  "<< longestCommonPrefix(ar, n);
    return 0;
}
