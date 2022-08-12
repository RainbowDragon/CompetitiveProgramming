/**
 *      CSES Problem Set - Two Sets II
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    int n;
    cin >> n;

    int sum = n*(n+1)/2;

    if (sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int half = sum / 2;
    int dp[half+1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
        for (int j = half; j >= 1; j--)
        {
            if (j >= i) {
                dp[j] += dp[j-i];
                dp[j] %= MOD;
            }
        }

    cout << dp[half] << endl;

    return 0;
}
