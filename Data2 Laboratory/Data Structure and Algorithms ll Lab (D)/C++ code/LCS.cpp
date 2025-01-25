// The longest common subsequence
// Length and the LCS

//#include<bits/stdc++.h>
#include<cstring>
#include <iostream>
using namespace std;

void lcsAlgo(string &S1, string &S2, int m, int n) {
    int LCS_table[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS_table[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            else
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
        }
    }
    
    int index = LCS_table[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcsAlgo[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }

        else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }

  
    cout << "S1 : " << S1 << "\nS2 : " << S2 <<endl;
    cout<<"LCS length: "<<LCS_table[m][n]<<endl;
    cout<<"LCS: " << lcsAlgo <<endl;

}

int main() {
    // char S1[] = "AGGTAB";
    // char S2[] = "GXTXAYB";
    //char S1[100],S2[100];
    string S1,S2;
    cin>>S1>>S2;
    int m=S1.size();
    int n=S2.size();
    // int m = strlen(S1);
    // int n = strlen(S2);

    lcsAlgo(S1, S2, m, n);
}