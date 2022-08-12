/**
 *      CSES Problem Set - Grid Paths
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int h[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }    

    int dp[x+1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++)
        for (int j = x; j >= 0; j--)
        {
            if (j >= h[i]) {
                dp[j] = max(dp[j], dp[j-h[i]]+s[i]);
            }
        }

    cout << dp[x] << endl;

    return 0;
}
