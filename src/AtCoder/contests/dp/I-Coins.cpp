/**
 *      AtCoder Educational DP Contest - I. Coins
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    double prob[N];

    for (int i = 0; i < N; i++)
    {
        cin >> prob[i];
    }

    double dp[N][N+1];
    for (int i = 0; i <= N; i++)
    {
        dp[0][i] = 0;
    }
    dp[0][0] = 1 - prob[0];
    dp[0][1] = prob[0];

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = dp[i-1][0]*(1 - prob[i]);
        for (int j = 1; j <= i+1; j++)
        {
            dp[i][j] = dp[i-1][j-1]*prob[i] + dp[i-1][j]*(1 - prob[i]);
        }
        for (int j = i+2; j <= N; j++)
        {
            dp[i][j] = 0;
        }
    }

    double result = 0;
    int moreHeads = N/2 + 1;
    for (int i = moreHeads; i <= N; i++)
    {
        result += dp[N-1][i];
    }

    cout << fixed << setprecision(10) << result << endl;

    return 0;
}
