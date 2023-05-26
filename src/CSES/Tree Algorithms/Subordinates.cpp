/**
 *      CSES Problem Set - Subordinates
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void dfs(vi* edge, int* result, int node)
{
    for (int next : edge[node])
    {
        dfs(edge, result, next);
        result[node] += result[next] + 1;
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    int result[n+1];
    memset(result, 0, sizeof result);

    vi edge[n+1];
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        edge[a].push_back(i);
    }

    dfs(edge, result, 1);

    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
