/**
 *      CSES Problem Set - Dynamic Programming - Coin Combinations II
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
 
int main()
{
    int n, x;
    cin >> n >> x;
    
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
 
    vector<int> dp(x+1, 0);
    dp[0] = 1;

    for (int c : coin)
    {
        for (int i = c; i <= x; i++)
        {
            dp[i] += dp[i-c];
            dp[i] %= MOD;
        }
    }
    
    cout << dp[x] << endl;
 
    return 0;
}