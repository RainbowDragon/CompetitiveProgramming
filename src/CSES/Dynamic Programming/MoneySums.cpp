/**
 *      CSES Problem Set - Money Sums
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int coin[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
        sum += coin[i];
    }
    sort(coin, coin+n);

    bool dp[sum+1];
    memset(dp, false, sizeof dp);

    dp[0] = true;
    int count = 0;
    for (int x : coin)
        for (int i = sum; i >= 1; i--)
        {
            if (i >= x && dp[i-x] && !dp[i]) {
                count++;
                dp[i] = true;
            }
        }

    cout << count << endl;
    for (int i = 1; i <= sum; i++)
    {
        if (dp[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
