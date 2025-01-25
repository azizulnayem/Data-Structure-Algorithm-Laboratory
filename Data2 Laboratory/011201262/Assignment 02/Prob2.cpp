#include <bits/stdc++.h>
using namespace std;

#define row 10000
#define col 10000

int N, W, X, Y;
double P1, P2, dp[row][col];
int visit[row][col];
int temp;

double max_probability(int total_coin, int earned_point)
{
    if (earned_point >= W)
        return 1.0;
    if (total_coin == 0)
        return 0.0;

    double &ans = dp[total_coin][earned_point];
    int &vis = visit[total_coin][earned_point];

    if (vis == temp)
        return ans;
    ans = 0.0;
    vis = temp;

    double turn1 = P1 * max_probability(total_coin - 1, earned_point + X) + (1 - P1) * max_probability(total_coin - 1, earned_point);
    double turn2 = P2 * max_probability(total_coin - 1, earned_point + Y) + (1 - P2) * max_probability(total_coin - 1, earned_point);
    return ans = max(turn1, turn2);
}

int main()
{
    int T;
    cin >> T;
    temp = T;
    for (int i = 1; i <= T; i++)
    {
        cin >> X >> Y >> N >> W >> P1 >> P2;

        P1 /= 100.0;
        P2 /= 100.0;
    }
    printf("%.6lf", max_probability(N, 0) * 100.0);
}
