/**
 *      AtCoder Educational DP Contest - O. Matching
 *
 */

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // Use standard vectors safely allocated on the heap to avoid stack overflow
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    
    // dp[mask] stores the number of valid matchings for the first 'i' men 
    // with the subset of women represented by the bits in 'mask'
    vector<int> dp(1 << N, 0);
    dp[0] = 1;

    for (int mask = 0; mask < (1 << N); mask++)
    {
        int i = __builtin_popcount(mask);

        // BUG FIX: If i == N, all men are already matched. 
        // There is no man 'N' (indices are 0 to N-1), so break/continue to avoid array overflow.
        if (i == N) continue; 

        for (int j = 0; j < N; j++)
        {
            // If woman 'j' is not yet matched, and man 'i' is compatible with woman 'j'
            if (!(mask & (1 << j)) && a[i][j]) {
                int next_mask = mask | (1 << j);
                dp[next_mask] = (dp[next_mask] + dp[mask]) % MOD;
            }
        }
    }

    cout << dp[(1 << N) - 1] << "\n";

    return 0;
}