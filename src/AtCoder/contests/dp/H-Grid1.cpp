/**
 *      AtCoder Educational DP Contest - H. Grid 1
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    int H, W;
    cin >> H >> W;
    bool grid[H][W];

    for (int i = 0; i < H; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < W; j++)
        {
            grid[i][j] = (str[j] == '.');
        } 
    }

    ll dp[H][W];
    dp[0][0] = grid[0][0] ? 1 : 0;
    for (int i = 1; i < H; i++)
    {
        dp[i][0] = grid[i][0] ? dp[i-1][0] : 0;
    }
    for (int i = 1; i < W; i++)
    {
        dp[0][i] = grid[0][i] ? dp[0][i-1] : 0;
    }

    for (int i = 1; i < H; i++)
        for (int j = 1; j < W; j++)
        { 
            dp[i][j] = grid[i][j] ? dp[i-1][j]+dp[i][j-1] : 0;
            dp[i][j] %= MOD;
        }     

    cout << dp[H-1][W-1] << endl;

    return 0;
}
