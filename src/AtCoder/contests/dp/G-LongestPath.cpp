/**
 *      AtCoder Educational DP Contest - G. Longest Path
 *
 */

#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int>* graph, int* dp)
{
    if (dp[node] > 0) {
        return;
    }

    for (int next : graph[node]) 
    {
        dfs(next, graph, dp);
        dp[node] = max(dp[node], dp[next]+1);
    }

    return;
}

int main()
{
    int N, M;
    cin >> N >> M;

    int dp[N+1];
    memset(dp, 0, sizeof dp);
    vector<int> graph[N+1];

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    for (int i = 1; i <= N; i++)
    {
        dfs(i, graph, dp);
    }

    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        result = max(result, dp[i]);
    }

    cout << result << endl;

    return 0;
}
