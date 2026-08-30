/**
 *      CSES Problem Set - Dynamic Programming - Removing Digits
 *
 */

#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int n;
    cin >> n;
    
    vector<int> dp(n+1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i < 10) 
        {
            dp[i] = 1;
        }
        else 
        {
            int value = i;
            while (value > 0) 
            {
                int d = value % 10;
                dp[i] = min(dp[i], dp[i-d]+1);
                value /= 10;
            }
        }
    }
 
    cout << dp[n] << endl;
 
    return 0;
}