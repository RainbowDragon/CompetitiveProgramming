/**
 *      CSES Problem Set - Dynamic Programming - Rectangle Cutting
 *
 */

#include <bits/stdc++.h>

using namespace std;
 
int dp[501][501];
 
int dfs(int a, int b)
{
    if (a > b)
    {
        swap(a, b);
    }

    if (a == b) 
    {
        return 0;
    }
 
    if (dp[a][b] != -1) 
    {
        return dp[a][b];
    }
 
    int result = 1e9;

    for (int i = 1; i <= b/2; i++)
    {
        result = min(result, dfs(a, i)+dfs(a, b-i)+1);
    }
    
    for (int i = 1; i <= a/2; i++)
    {
        result = min(result, dfs(i, b)+dfs(a-i, b)+1);
    }
 
    dp[a][b] = result;
 
    return dp[a][b];
}
 
int main()
{
    int a, b;
    cin >> a >> b;
    
    memset(dp, -1, sizeof dp);
 
    cout << dfs(a, b) << endl;
 
    return 0;
}