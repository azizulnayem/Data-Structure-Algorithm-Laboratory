#include <bits/stdc++.h>
using namespace std;
int dp1[1000][10000], dp2[1000][10000];

int main()
{
    int N, T, i, j, k;
    cin >> T;
    cin >> N;
    int mi[T + 1], ti[T + 1];
    for (i = 0; i < T; i++)
    {
        cin >> mi[i + 1];
    }
    for (i = 0; i < T; i++)
    {
        cin >> ti[i + 1];
    }
    for (i = 0; i < T + 1; i++)
    {
        for (j = 0; j < N + 1; j++)
        {
            dp1[i][j] = 0;
            dp2[i][j] = 0;
        }
    }

    for (i = 1; i < T + 1; i++)
    {
        for (j = 1; j < N + 1; j++)
        {
            if (ti[i] <= j)
                dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - ti[i]] + mi[i]);
            else
                dp1[i][j] = dp1[i - 1][j];
            if (ti[i] <= j)
                dp2[i][j] = max(dp2[i - 1][j], dp1[i - 1][j - ti[i]] + 2 * mi[i]);
            else
                dp2[i][j] = dp2[i - 1][j];
            if (ti[i] <= j)
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - ti[i]] + mi[i]);

        }

    }
    cout << dp2[T][N] << endl;
}
