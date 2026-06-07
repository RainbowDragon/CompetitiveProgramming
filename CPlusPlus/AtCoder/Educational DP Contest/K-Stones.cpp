/**
 *      AtCoder Educational DP Contest - K. Stones
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    // Sorting allows us to break early in the inner loop
    sort(a.begin(), a.end());

    vector<bool> dp(K + 1, false);

    for (int i = 1; i <= K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Optimization: Since 'a' is sorted, if a[j] > i, all subsequent moves will also be too large
            if (a[j] > i) {
                break;
            }

            // If making a move of size a[j] leaves the opponent in a losing state, 
            // then the current state 'i' is a winning state.
            if (!dp[i - a[j]]) {
                dp[i] = true;
                break; // Optimization: Once 'i' is proven to be a winning state, skip remaining moves
            }
        }
    }

    cout << (dp[K] ? "First" : "Second") << endl;

    return 0;
}