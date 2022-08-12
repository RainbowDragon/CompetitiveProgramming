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
        for (int d = 1; d <= 6; d++)
        {
            if (i >= d) {
                dp[i] += dp[i-d];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}
