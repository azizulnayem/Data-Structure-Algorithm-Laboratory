#include<bits/stdc++.h>

using namespace std;

void Calc_LPS(char *pattern, int m, int *LPS)
{
    int len=0;
    int i=1;

    LPS[0]=0;

    while (i<m) ///until the length of pattern
    {
        if(pattern[len]==pattern[i])
        {
            LPS[i]=len+1;
            len++;
            i++;
        }
        else
        {
            if(len!=0)
                len=LPS[len-1];
            else{
                LPS[i]=0;
                i++;
            }
        }
    }

}


void KMP(char *text, char *pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);

    int LPS[m];
    Calc_LPS(pattern,m,LPS);

    /*
    ///test_code
    for(int i=0;i<m;i++)
    {
        cout<<LPS[i]<<"\t";
    }
    */

    int i=0;
    int j=0;

    while (i<n) /// Until the length of the text
    {
        ///Match
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }

        ///Not Match
        else
        {
            if(j!=0)
                j=LPS[j-1];
            else
                i++;
        }
        ///if (j==m)

        if(j==m)
        {
            cout<< "Match Found at " << (i-j) << "th index" << endl;
            j=LPS[j-1];
        }
    }


}


int main()
{
/// test case 1:
//text="ABABCABCABABABD";
//pattern = "ABABD";

    char text[]= "ABACBACD";
    char pattern[] = "BAC";

    KMP(text, pattern);
    return 0;
}
