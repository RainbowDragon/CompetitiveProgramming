/**
 *      AtCoder Educational DP Contest - N. Slimes
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;

    int a[N+1];
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    ll prefixSum[N+1];
    prefixSum[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        prefixSum[i] = prefixSum[i-1] + a[i];
    }

    ll dp[N+1][N+1];
    memset(dp, 0, sizeof dp);

    for (int j = 1; j < N; j++)
    {
        for (int i = 1; i+j <= N; i++)
        {
            dp[i][i+j] = 1e13;
            for (int k = i; k < i+j; k++)
            {
                dp[i][i+j] = min(dp[i][i+j], dp[i][k]+dp[k+1][i+j]);
            }
            dp[i][i+j] += (prefixSum[i+j] - prefixSum[i-1]);
        }
    }

    cout << dp[1][N] << endl;

    return 0;
}
