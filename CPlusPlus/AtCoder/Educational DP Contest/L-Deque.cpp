/**
 *      AtCoder Educational DP Contest - L. Deque
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

    int N;
    if (!(cin >> N)) return 0;

    vector<ll> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    // dp[i] will dynamically represent the maximum relative score for an interval starting at 'i'
    // Base case: Intervals of length 1 (j = 0). The only choice is to take the single element.
    vector<ll> dp(N);
    for (int i = 0; i < N; i++)
    {
        dp[i] = a[i];
    }

    // Iterate by interval length (len goes from 2 up to N)
    for (int len = 2; len <= N; len++)
    {
        // Calculate DP values for intervals of the current length
        for (int i = 0; i <= N - len; i++)
        {
            int j = i + len - 1; // End index of the interval

            // dp[i+1] currently holds the value for interval [i+1, j] (from length len-1)
            // dp[i] currently holds the value for interval [i, j-1] (from length len-1)
            dp[i] = max(a[i] - dp[i + 1], a[j] - dp[i]);
        }
    }

    // The answer for the full deck spanning from index 0 to N-1
    cout << dp[0] << "\n";

    return 0;
}