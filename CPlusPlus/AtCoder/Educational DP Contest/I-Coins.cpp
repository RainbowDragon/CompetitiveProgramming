/**
 *      AtCoder Educational DP Contest - I. Coins
 *
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // dp[j] stores the probability of getting exactly 'j' heads so far
    // Allocated safely on the heap and automatically initialized to 0.0
    vector<double> dp(N + 1, 0.0);
    
    // Base case: Before tossing any coins, the probability of 0 heads is 1.0
    dp[0] = 1.0;

    // Process each coin one by one
    for (int i = 0; i < N; i++)
    {
        double p_head;
        cin >> p_head;
        double p_tail = 1.0 - p_head;

        // Iterate BACKWARDS so we don't overwrite states from the previous iteration
        // j goes up to i + 1 because with i+1 coins, you can have at most i+1 heads
        for (int j = i + 1; j >= 0; j--)
        {
            if (j == 0) {
                dp[j] = dp[j] * p_tail;
            } else {
                dp[j] = dp[j] * p_tail + dp[j - 1] * p_head;
            }
        }
    }

    // Sum up the probabilities where the number of heads is strictly greater than N / 2
    double total_probability = 0;
    for (int j = N / 2 + 1; j <= N; j++)
    {
        total_probability += dp[j];
    }

    cout << fixed << setprecision(10) << total_probability << "\n";

    return 0;
}