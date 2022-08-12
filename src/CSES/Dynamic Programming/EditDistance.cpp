/**
 *      CSES Problem Set - Edit Distance
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string first, second;
    cin >> first >> second;
    
    int n = first.length();
    int m = second.length();

    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i-1][j-1];
            if (first[i-1] != second[j-1]) {
                dp[i][j]++;
            }
            dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
        }

    cout << dp[n][m] << endl;

    return 0;
}
