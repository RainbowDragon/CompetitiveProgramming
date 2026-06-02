/**
 *      AtCoder Educational DP Contest - C. Vacation
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // We only need to store the DP results of the "previous day"
    // Initialize for Day 1 (index 0)
    int prev_A, prev_B, prev_C;
    cin >> prev_A >> prev_B >> prev_C;

    // Process Days 2 to N dynamically
    for (int i = 1; i < N; i++)
    {
        int curr_A, curr_B, curr_C;
        cin >> curr_A >> curr_B >> curr_C;

        // Calculate maximums for the current day using the previous day's data
        int next_A = max(prev_B, prev_C) + curr_A;
        int next_B = max(prev_A, prev_C) + curr_B;
        int next_C = max(prev_A, prev_B) + curr_C;

        // Move forward to the next day
        prev_A = next_A;
        prev_B = next_B;
        prev_C = next_C;
    }

    // The answer is the maximum value possible on the final day
    cout << max({prev_A, prev_B, prev_C}) << "\n";

    return 0;
}