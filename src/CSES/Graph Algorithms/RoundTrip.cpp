/**
 *      CSES Problem Set - Round Trip
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

bool dfs(vi* edge, int* parent, int node, int p)
{
    if (parent[node] != 0) {
        vi result;
        result.push_back(node);
        int current = p;
        while (current != node)
        {
            result.push_back(current);
            current = parent[current];
        }
        result.push_back(node);
        cout << result.size() << endl;
        for (int i : result)
        {
            cout << i << " ";
        }
        cout << endl;

        return true;
    }

    parent[node] = p;

    for (int next : edge[node])
    {
        if (next != p) {
            if (dfs(edge, parent, next, node)) {
                return true;
            }
        }
    }

    return false;
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

    int parent[n+1];
    memset(parent, 0, sizeof parent);

    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == 0) {
            found = dfs(edge, parent, i, i);
            if (found) {
                break;
            }
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
