/**
 *      CSES Problem Set - Labyrinth
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char dir[] = {'U', 'L', 'D', 'R'};

int main()
{
    int n, m;
    cin >> n >> m;

    int graph[n][m];
    pii A = {0, 0};
    pii B = {0, 0};
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '.') {
                graph[i][j] = -1;
            }
            else if (str[j] == 'A') {
                graph[i][j] = 0;
                A = {i, j};
            }
            else if (str[j] == 'B') {
                graph[i][j] = -1;
                B = {i, j};
            }
            else {
                graph[i][j] = -2;
            }
        }
    }

    char direction[n][m];
    pii parent[n][m];
    queue<pii> q;
    q.push(A);

    while (!q.empty()) 
    {
        pii current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;
        int dist = graph[x][y];

        if (x == B.first && y == B.second) {
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

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && graph[nx][ny] == -1) {
                q.push({nx, ny});
                graph[nx][ny] = ndist;
                direction[nx][ny] = dir[i];
                parent[nx][ny] = {x, y}; 
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
