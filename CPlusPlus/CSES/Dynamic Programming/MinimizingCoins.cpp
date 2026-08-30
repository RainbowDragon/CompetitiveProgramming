/**
 *      CSES Problem Set - Dynamic Programming - Minimizing Coins
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
 
    vector<int> dp(x+1, 1e9);
    dp[0] = 0;

    for (int c : coin)
        for (int i = c; i <= x; i++)
        {
            dp[i] = min(dp[i], dp[i-c]+1);
        }
     
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << endl;
 
    return 0;
}