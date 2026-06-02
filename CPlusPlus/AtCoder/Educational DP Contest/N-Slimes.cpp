/**
 *      AtCoder Educational DP Contest - N. Slimes
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// Use a safe infinity that won't clip maximum possible combinations
const ll INF = 1e18; 

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // Build the prefix sum array directly on the fly
    vector<ll> prefixSum(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        ll val;
        cin >> val;
        prefixSum[i] = prefixSum[i - 1] + val;
    }

    // Allocate DP matrix safely on the heap
    // dp[i][j] stores the minimum cost to merge candies from index i to j
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));

    // 'len' represents the length of the interval we are merging (from 2 up to N)
    for (int len = 2; len <= N; len++)
    {
        for (int i = 1; i <= N - len + 1; i++)
        {
            int j = i + len - 1; // End index of the interval
            
            dp[i][j] = INF;

            // Try every possible split point 'k' between i and j-1
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }

            // Add the cost of the final merge step for the entire range [i, j]
            dp[i][j] += (prefixSum[j] - prefixSum[i - 1]);
        }
    }

    cout << dp[1][N] << "\n";

    return 0;
}