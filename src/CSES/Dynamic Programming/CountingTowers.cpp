/**
 *      CSES Problem Set - Counting Towers
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    int t;
    cin >> t;
    
    int n[t];
    int maxN = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
        maxN = max(maxN, n[i]);
    }

    ll dp1[maxN+1], dp2[maxN+1];
    dp1[1] = dp2[1] = 1;
    for (int i = 2; i <= maxN; i++)
    {
        dp1[i] = 2*dp1[i-1] + dp2[i-1];
        dp1[i] %= MOD;
        dp2[i] = dp1[i-1] + 4*dp2[i-1];
        dp2[i] %= MOD;
    }

    for (int i = 0; i < t; i++)
    {
        cout << (dp1[n[i]] + dp2[n[i]]) % MOD << endl;
    }

    return 0;
}
