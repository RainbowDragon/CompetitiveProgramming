/**
 *      CSES Problem Set - Rectangle Cutting
 *
 */

#include <bits/stdc++.h>

using namespace std;

int dp[501][501];

int dfs(int a, int b)
{
    if (a == b) {
        return 0;
    }

    if (dp[a][b] > 0 || dp[b][a] > 0) {
        return dp[a][b];
    }

    int result = 1e9;
    for (int i = 1; i < b; i++)
    {
        result = min(result, dfs(a, i)+dfs(a, b-i)+1);
    }
    for (int i = 1; i < a; i++)
    {
        result = min(result, dfs(i, b)+dfs(a-i, b)+1);
    }

    dp[a][b] = dp[b][a] = result;

    return dp[a][b];
}

int main()
{
    int a, b;
    cin >> a >> b;
    
    memset(dp, 0, sizeof dp);

    cout << dfs(a, b) << endl;

    return 0;
}
