/**
 *      CSES Problem Set - Coin Combinations II
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
    sort(coin, coin+n);

    ll dp[x+1];
    memset(dp, 0, sizeof dp);

    dp[0] = 1;
    for (int c : coin)
    {
        for (int i = 1; i <= x; i++)
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
