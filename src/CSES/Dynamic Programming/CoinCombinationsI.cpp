/**
 *      CSES Problem Set - Coin Combinations I
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    int n, x;
    cin >> n >> x;
    
    int coin[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    ll dp[x+1];

    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        dp[i] = 0;
        for (int c : coin)
        {
            if (i >= c) {
                dp[i] += dp[i-c];
                dp[i] %= MOD;
            }
        }
    }
    
    cout << dp[x] << endl;

    return 0;
}
