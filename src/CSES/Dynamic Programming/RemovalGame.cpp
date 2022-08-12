/**
 *      CSES Problem Set - Removal Game
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    
    int x[n];
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sum += x[i];
    }

    ll dp[n][n];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = x[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i+j < n; i++)
        {
            dp[i][i+j] = max(x[i]-dp[i+1][i+j], x[i+j]-dp[i][i+j-1]);
        }
    }

    cout << (sum + dp[0][n-1])/2 << endl; 

    return 0;
}
