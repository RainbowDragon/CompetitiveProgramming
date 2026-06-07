/**
 *      AtCoder Educational DP Contest - H. Grid 1
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    if (!(cin >> H >> W)) return 0;

    // dp[j] stores the number of paths to reach the current cell in column j
    vector<ll> dp(W, 0);
    
    // Base case: Starting position has 1 way to be reached
    dp[0] = 1;

    for (int i = 0; i < H; i++)
    {
        string row_str;
        cin >> row_str; // Process the grid on the fly, row by row

        for (int j = 0; j < W; j++)
        {
            if (row_str[j] == '#') {
                // If it's a wall, no paths can pass through it
                dp[j] = 0;
            } 
            else {
                // If it's empty, add the paths from the left cell (dp[j-1])
                // The current dp[j] already holds the value from the row above!
                if (j > 0) {
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;
                }
            }
        }
    }

    cout << dp[W - 1] << endl;

    return 0;
}