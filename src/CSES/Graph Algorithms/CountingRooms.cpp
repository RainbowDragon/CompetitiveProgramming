/**
 *      CSES Problem Set - Counting Rooms
 *
 */

#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[1000][1000];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1}; 

void floodfill(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m || graph[i][j] != 0) {
        return;
    }

    graph[i][j] = 2;

    for (int k = 0; k < 4; k++)
    {
        floodfill(i+dx[k], j+dy[k]);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = ((str[j] == '.') ? 0 : 1);
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 0) {
                result++;
                floodfill(i, j);
            }
        }
    
    cout << result << endl;

    return 0;
}
