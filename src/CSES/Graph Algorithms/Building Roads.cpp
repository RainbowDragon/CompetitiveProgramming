/**
 *      CSES Problem Set - Building Roads
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int find(int* parent, int node)
{
    int cur = node;
    while (parent[cur] != cur)
    {
        cur = parent[cur];
    }
    parent[node] = cur;

    return cur;
}

bool connect(int* parent, int n1, int n2)
{
    int p1 = find(parent, n1);
    int p2 = find(parent, n2);

    if (p1 != p2) {
        parent[p1] = parent[p2] = min(p1, p2);
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    pii road[m];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        road[i] = {a, b};
    }

    int parent[n+1];
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int count = n;
    for (int i = 0; i < m; i++)
    {
        if (connect(parent, road[i].first, road[i].second)) {
            count--;
        }
    }

    if (count == 1) {
        cout << 0 << endl;
    }
    else {
        cout << count-1 << endl;
        set<int> mySet;
        for (int i = 1; i <= n; i++)
        {
            mySet.insert(find(parent, i));
        }

        int index = 0;
        int last = 0;
        for (int node : mySet)
        {
            if (index > 0) {
                cout << last << " " << node << endl;
            }
            index++;
            last = node;
        }
    }

    return 0;
}
