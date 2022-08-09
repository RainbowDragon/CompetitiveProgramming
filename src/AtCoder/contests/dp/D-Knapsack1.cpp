/**
 *      AtCoder Educational DP Contest - D. Knapsack 1
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int N, W;
    cin >> N >> W;
    int weight[N], value[N];
    ll dp[N][W+1];

    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }

    for (int i = 0; i < N; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= W; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= weight[i]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }

    cout << dp[N-1][W] << endl;

    return 0;
}
