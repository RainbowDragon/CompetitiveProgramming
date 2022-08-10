/**
 *      AtCoder Educational DP Contest - F. LCS
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int m = s.size();
    int n = t.size();

    int dp[m+1][n+1];

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= n; j++)
        { 
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }     
    }

    string result = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s[i-1] == t[j-1]) {
            result = s[i-1] + result;
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else {
            j--;
        }
    }

    cout << result << endl;

    return 0;
}
