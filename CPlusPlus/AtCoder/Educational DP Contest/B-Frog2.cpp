/**
 *      AtCoder Educational DP Contest - B. Frog 2
 *
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<int> height(N);
    for (int i = 0; i < N; i++)
    {
        cin >> height[i];
    }

    // dp[i] will store the minimum cost to reach stone i
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;

    // DP: Calculate the min cost for stone i by looking back at previous K stones
    for (int i = 1; i < N; i++)
    {
        // Look back up to K steps, but don't go past stone 0
        for (int j = 1; j <= K && i - j >= 0; j++)
        {
            dp[i] = min(dp[i], dp[i - j] + abs(height[i] - height[i - j]));
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}