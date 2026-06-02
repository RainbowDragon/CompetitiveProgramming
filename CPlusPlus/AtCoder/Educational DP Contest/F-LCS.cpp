/**
 *      AtCoder Educational DP Contest - F. LCS
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    if (!(cin >> s >> t)) return 0;

    int m = s.size();
    int n = t.size();

    // Allocate memory safely on the heap to avoid stack overflow.
    // This automatically initializes the entire 2D grid to 0.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        { 
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }     
    }

    // Backtrack to find the actual LCS string
    string result = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s[i-1] == t[j-1]) {
            // OPTIMIZATION: push_back is O(1). Do not prepend with '+'
            result.push_back(s[i-1]); 
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else {
            j--;
        }
    }

    // Since we appended characters backwards, reverse the string once at the end
    reverse(result.begin(), result.end());

    cout << result << "\n";

    return 0;
}