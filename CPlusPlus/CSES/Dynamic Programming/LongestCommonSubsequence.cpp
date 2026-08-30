/**
 *      CSES Problem Set - Dynamic Programming - Longest Common Subsequence
 *
 */

#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
 
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
 
    vector<int> b(m+1);
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }    
 
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    
    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            lcs.push_back(a[i]);
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());

    cout << dp[n][m] << endl;
    for (size_t i = 0; i < lcs.size(); i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << lcs[i];
    }
    cout << endl;

    return 0;
}