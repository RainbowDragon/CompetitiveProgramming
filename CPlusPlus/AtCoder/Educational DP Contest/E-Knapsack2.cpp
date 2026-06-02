/**
 *      AtCoder Educational DP Contest - E. Knapsack 2
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// A safe "infinity" value for weights that won't overflow when adding
const ll INF = 1e15; 

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, W;
    if (!(cin >> N >> W)) return 0;

    // Read inputs on the fly and track the maximum possible value sum
    vector<pair<int, int>> items(N);
    int max_value_sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> items[i].first >> items[i].second; // first = weight, second = value
        max_value_sum += items[i].second;
    }

    // dp[j] stores the minimum weight needed to get exactly value 'j'
    // Dynamic size based on actual input instead of a rigid 1e5+1
    vector<ll> dp(max_value_sum + 1, INF);
    dp[0] = 0;

    // Process each item
    for (int i = 0; i < N; i++)
    {
        int w = items[i].first;
        int v = items[i].second;

        // Loop backwards, stopping at 'v' to eliminate the internal 'if' check
        for (int j = max_value_sum; j >= v; j--)
        {
            if (dp[j - v] != INF) { // Only transition from a reachable value state
                dp[j] = min(dp[j], dp[j - v] + w);
            }
        }
    }

    // Find the maximum value achievable within the weight limit W
    for (int j = max_value_sum; j >= 0; j--)
    {
        if (dp[j] <= W) {
            cout << j << "\n";
            break;
        }
    }

    return 0;
}