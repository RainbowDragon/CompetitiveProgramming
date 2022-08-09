/**
 *      AtCoder Educational DP Contest - B. Frog 2
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int height[N];
    int dp[N];

    for (int i = 0; i < N; i++)
    {
        cin >> height[i];
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for (int i = 0; i < N; i++)
        for (int j = 1; j <= K; j++)
        {
            if (i + j < N) {
                dp[i+j] = min(dp[i+j], dp[i] + abs(height[i+j] - height[i]));
            }
        }

    cout << dp[N-1] << endl;

    return 0;
}
