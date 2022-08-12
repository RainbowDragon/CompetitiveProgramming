/**
 *      CSES Problem Set - Array Description
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

    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    ll dp[m+2];
    memset(dp, 0, sizeof dp);
    if (x[0] != 0) {
        dp[x[0]] = 1;
    }
    else {
        for (int i = 1; i <= m; i++)
        {
            dp[i] = 1;
        }
    }

    ll temp[m+2];
    memset(temp, 0, sizeof temp);
    for (int i = 1; i < n; i++)
    {
        int value = x[i];
        if (value != 0) {
            dp[value] += dp[value-1];
            dp[value] += dp[value+1];
            dp[value] %= MOD;
            value = dp[value];

            for (int j = 1; j <= m; j++)
            {
                dp[j] = 0;
            }

            dp[x[i]] = value;
        }
        else {
            for (int j = 1; j <= m; j++)
            {
                temp[j] = dp[j];
                temp[j] += dp[j-1];
                temp[j] += dp[j+1];
                temp[j] %= MOD;
            }
            
            for (int j = 1; j <= m; j++)
            {
                dp[j] = temp[j];
            }
        }
    }

    ll result = 0;
    for (int i = 1; i <= m; i++)
    {
        result += dp[i];
        result %= MOD;
    }

    cout << result << endl;

    return 0;
}
