/**
 *      CSES Problem Set - Dynamic Programming - Rectangle Cutting
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    vector<vector<int>> dp(a+1, vector<int>(b+1, 0));
 
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
        {
            if (i == j) 
            {
                continue;
            }

            int result = 1e9;
            for (int k = 1; k <= i/2; k++)
            {
                result = min(result, dp[k][j]+dp[i-k][j]+1);
            }
            for (int k = 1; k <= j/2; k++)
            {
                result = min(result, dp[i][k]+dp[i][j-k]+1);
            }
            dp[i][j] = result;
        }

    cout << dp[a][b] << endl;
 
    return 0;
}