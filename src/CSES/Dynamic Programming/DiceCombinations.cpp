/**
 *      CSES Problem Set - Dice Combinations
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    int n;
    cin >> n;
    
    ll dp[n+1];
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        if (i >= 1) {
            dp[i] += dp[i-1];
            dp[i] %= MOD;
        }
        if (i >= 2) {
            dp[i] += dp[i-2];
            dp[i] %= MOD;
        }
        if (i >= 3) {
            dp[i] += dp[i-3];
            dp[i] %= MOD;
        }
        if (i >= 4) {
            dp[i] += dp[i-4];
            dp[i] %= MOD;
        }
        if (i >= 5) {
            dp[i] += dp[i-5];
            dp[i] %= MOD;
        }
        if (i >= 6) {
            dp[i] += dp[i-6];
            dp[i] %= MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}
