/**
 *      AtCoder Educational DP Contest - A. Frog 1
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int height[N];

    for (int i = 0; i < N; i++)
    {
        cin >> height[i];
    }

    int dp[N];
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);

    for (int i = 2; i < N; i++)
    {
        dp[i] = min(abs(height[i] - height[i-1]) + dp[i-1], abs(height[i] - height[i-2]) + dp[i-2]);
    }

    cout << dp[N-1] << endl;

    return 0;
}
