/**
 *      CSES Problem Set - Monsters
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char dir[] = {'U', 'L', 'D', 'R'};

int main()
{
    int n, m;
    cin >> n >> m;

    int graph1[n][m];
    int graph2[n][m];
    pii A = {0, 0};
    vpii monster;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '.') {
                graph1[i][j] = graph2[i][j] = -1;
            }
            else if (str[j] == 'A') {
                graph1[i][j] = -1;
                graph2[i][j] = 0;
                A = {i, j};
            }
            else if (str[j] == 'M') {
                graph1[i][j] = 0;
                graph2[i][j] = -1;
                monster.push_back({i, j});
            }
            else {
                graph1[i][j] = graph2[i][j] = -2;
            }
        }
    }

    queue<pii> q1;
    for (pii m : monster)
    {
        q1.push(m);
    }

    while (!q1.empty()) 
    {
        pii current = q1.front();
        q1.pop();

        int x = current.first;
        int y = current.second;
        int dist = graph1[x][y];

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ndist = dist + 1;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && graph1[nx][ny] == -1) {
                q1.push({nx, ny});
                graph1[nx][ny] = ndist;
            }
        }
    }

    char direction[n][m];
    pii parent[n][m];
    queue<pii> q2;
    q2.push(A);

    while (!q2.empty())
    {
        pii current = q2.front();
        q2.pop();

        int x = current.first;
        int y = current.second;
        int dist = graph2[x][y];

        if (x == 0 || x == n-1 || y == 0 || y == m-1) {
            cout << "YES" << endl;
            cout << dist << endl;
            
            string path(dist, ' ');
            int cx = x;
            int cy = y;
            int index = dist - 1;
            while (index >= 0)
            {
                path[index] = direction[cx][cy];
                pii next = parent[cx][cy];
                cx = next.first;
                cy = next.second;
                index--;
            }
            cout << path << endl;

            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ndist = dist + 1;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && graph2[nx][ny] == -1 && (ndist < graph1[nx][ny] || graph1[x][y] == -1)) {
                q2.push({nx, ny});
                graph2[nx][ny] = ndist;
                direction[nx][ny] = dir[i];
                parent[nx][ny] = {x, y}; 
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
