/**
 *      AtCoder Educational DP Contest - D. Knapsack 1
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, W;
    if (!(cin >> N >> W)) return 0;

    // dp[j] stores the maximum value under the weight 'j'
    vector<ll> dp(W + 1, 0);

    // Process each item on the fly without storing them in arrays
    for (int i = 0; i < N; i++)
    {
        int w, v;
        cin >> w >> v;

        // Loop stops automatically when j < w, eliminating the internal 'if' check
        for (int j = W; j >= w; j--)
        {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    cout << dp[W] << endl;

    return 0;
}