/**
 *      AtCoder Educational DP Contest - L. Deque
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    ll dp[N][N];
    memset(dp, false, sizeof dp);

    for (int i = 0; i < N; i++)
    {
        dp[i][i] = a[i];
    }

    for (int j = 1; j < N; j++)
    {
        for (int i = 0; i+j < N; i++)
        {
            dp[i][i+j] = max(a[i]-dp[i+1][i+j], a[i+j]-dp[i][i+j-1]);
        }
    }

    cout << dp[0][N-1] << endl;

    return 0;
}
