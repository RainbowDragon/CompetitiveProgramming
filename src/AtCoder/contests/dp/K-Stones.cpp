/**
 *      AtCoder Educational DP Contest - K. Stones
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    bool dp[K+1];
    memset(dp, false, sizeof dp);

    for (int i = 1; i <= K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[j] <= i && !dp[i-a[j]]) {
                dp[i] = true;
            }
        }
    }

    cout << (dp[K] ? "First" : "Second") << endl;

    return 0;
}
