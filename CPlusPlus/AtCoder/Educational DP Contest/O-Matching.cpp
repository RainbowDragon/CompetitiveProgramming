/**
 *      AtCoder Educational DP Contest - O. Matching
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main()
{
    int N;
    cin >> N;

    int a[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> a[i][j];
        }
    
    int dp[1 << N];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for (int mask = 0; mask < (1 << N); mask++)
    {
        int i = __builtin_popcount(mask);

        for (int j = 0; j < N; j++)
        {
            if (!(mask & (1 << j)) && a[i][j])
            {
                int next_mask = mask | (1 << j);
                dp[next_mask] = (dp[next_mask] + dp[mask]) % MOD;
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}