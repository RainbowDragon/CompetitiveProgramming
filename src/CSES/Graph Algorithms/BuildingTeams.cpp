/**
 *      CSES Problem Set - Building Teams
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

bool dfs(vi* edge, int* group, int node, int g)
{
    if (group[node] != 0) {
        return group[node] == g;
    }

    group[node] = g;
    for (int next : edge[node])
    {
        if (group[next] == 0) {
            if (!dfs(edge, group, next, g*(-1))) {
                return false;
            }
        }
        else {
            if (group[next] == g) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vi edge[n+1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int group[n+1];
    memset(group, 0, sizeof group);

    for (int i = 1; i <= n; i++)
    {
        if (group[i] == 0) {
            if (!dfs(edge, group, i, 1)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << (group[i] > 0 ? 1 : 2) << " ";
    }
    cout << endl;

    return 0;
}
