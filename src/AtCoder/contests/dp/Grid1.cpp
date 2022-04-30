/**
 *      AtCoder Educational DP Contest - H. Grid 1
 *
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int main()
{
    int h, w;
    cin >> h >> w;
    bool grid[h][w];

    for (int i = 0; i < h; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < w; j++)
        {
            grid[i][j] = (str[j] == '.');
        } 
    }

    ll dp[h][w];
    dp[0][0] = grid[0][0] ? 1 : 0;
    for (int i = 1; i < h; i++)
    {
        dp[i][0] = grid[i][0] ? dp[i-1][0] : 0;
    }
    for (int i = 1; i < w; i++)
    {
        dp[0][i] = grid[0][i] ? dp[0][i-1] : 0;
    }

    for (int i = 1; i < h; i++)
        for (int j = 1; j < w; j++)
        { 
            dp[i][j] = grid[i][j] ? dp[i-1][j]+dp[i][j-1] : 0;
            dp[i][j] %= MOD;
        }     

    cout << dp[h-1][w-1] << endl;

    return 0;
}
