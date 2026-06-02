/**
 *      AtCoder Educational DP Contest - G. Longest Path
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DFS function using pull-DP with proper completion tracking
int dfs(int node, const vector<vector<int>>& graph, vector<int>& dp)
{
    // If the value is not -1, it has been fully computed and memoized
    if (dp[node] != -1) {
        return dp[node];
    }

    int max_len = 0;
    for (int next : graph[node]) 
    {
        // The path length from 'node' is 1 + the longest path starting from 'next'
        max_len = max(max_len, 1 + dfs(next, graph, dp));
    }

    // Memoize the final computed result for this node
    return dp[node] = max_len;
}

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    // Use standard safe layout on the heap to avoid Stack Overflow
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    // Initialize DP array with -1 to properly identify unvisited nodes
    vector<int> dp(N + 1, -1);

    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        result = max(result, dfs(i, graph, dp));
    }

    cout << result << "\n";

    return 0;
}