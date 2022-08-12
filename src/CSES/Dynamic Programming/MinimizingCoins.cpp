/**
 *      CSES Problem Set - Minimizing Coins
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    
    int coin[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    int dp[x+1];
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        dp[i] = 1e9;
        for (int c : coin)
        {
            if (i >= c) {
                dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
    }

    if (dp[x] == 1e9) {
        dp[x] = -1;
    }
    
    cout << dp[x] << endl;

    return 0;
}
