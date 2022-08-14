/**
 *      CSES Problem Set - Message Route
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

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
    int distance[n+1];
    memset(parent, 0, sizeof parent);
    memset(distance, 0, sizeof distance);

    queue<int> q;
    q.push(1);
    distance[1] = 1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current == n) {
            int dist = distance[current];
            cout << dist << endl;

            int path[dist];
            int index = dist - 1;
            while (index >= 0)
            {
                path[index] = current;
                current = parent[current];
                index--;
            }

            for (int node : path)
            {
                cout << node << " ";
            }
            cout << endl;

            return 0;
        }

        for (int next : edge[current])
        {
            if (distance[next] == 0)
            {
                q.push(next);
                distance[next] = distance[current]+1;
                parent[next] = current;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
