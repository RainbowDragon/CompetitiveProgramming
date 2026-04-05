/**
 *      AtCoder Educational DP Contest - M. Candies
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    int N, K;
    cin >> N >> K;

    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    ll dp[K+1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    ll prefix[K+1];
    memset(prefix, 0, sizeof prefix);

    for (int i = 0; i < N; i++)
    {
        prefix[0] = dp[0];   
        for (int j = 1; j <= K; j++)
        {
            prefix[j] = prefix[j-1] + dp[j];
            prefix[j] %= MOD;
        }

        for (int j = 0; j <= K; j++)
        {
            int index = j - a[i] - 1;

            if (index >= 0)
            {
                dp[j] = (prefix[j] - prefix[index] + MOD) % MOD;
            }
            else
            {
                dp[j] = prefix[j];
            }
        }
    }

    cout << dp[K] << endl;

    return 0;
}