/**
 *      AtCoder Educational DP Contest - A. Frog 1
 *
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> height(N);
    for (int i = 0; i < N; i++)
    {
        cin >> height[i];
    }

    // Edge case: If there's only 1 stone, the cost is 0
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Instead of a DP array, we just track the last two minimum costs
    int prev2 = 0;                                 // Equivalent to dp[i-2] (initially dp[0])
    int prev1 = abs(height[1] - height[0]);        // Equivalent to dp[i-1] (initially dp[1])

    for (int i = 2; i < N; i++)
    {
        int current_cost = min(abs(height[i] - height[i-1]) + prev1, 
                               abs(height[i] - height[i-2]) + prev2);
        
        // Shift our variables forward for the next iteration
        prev2 = prev1;
        prev1 = current_cost;
    }

    cout << prev1 << endl;

    return 0;
}