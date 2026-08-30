/**
 *      CSES Problem Set - Dynamic Programming - Array Description
 *
 */

#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    int n, m;
    cin >> n >> m;
 
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
 
    vector<ll> dp(m+2, 0);
    if (x[0] != 0) 
    {
        dp[x[0]] = 1;
    }
    else 
    {
        for (int i = 1; i <= m; i++)
        {
            dp[i] = 1;
        }
    }
 
    for (int i = 1; i < n; i++)
    {
        vector<ll> temp(m+2, 0);

        if (x[i] != 0)
        {
            int k = x[i];
            temp[k] = dp[k-1] + dp[k] + dp[k+1];
            temp[k] %= MOD;
        }
        else 
        {
            for (int k = 1; k <= m; k++)
            {
                temp[k] = dp[k-1] + dp[k] + dp[k+1];
                temp[k] %= MOD;                
            }
        }

        dp = move(temp);
    }
 
    ll result = 0;
    for (int k = 1; k <= m; k++)
    {
        result += dp[k];
        result %= MOD;
    }
 
    cout << result << endl;
 
    return 0;
}