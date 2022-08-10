/**
 *      AtCoder Educational DP Contest - J. Sushi
 *
 */

#include <bits/stdc++.h>

using namespace std;

int N;
double dp[301][301][301];

double dfs(int x, int y, int z)
{
    if (x < 0 || y < 0 || z < 0) {
        return 0;
    }

    if (x == 0 && y == 0 && z == 0) {
        return 0;
    }

    if (dp[x][y][z] > 0) {
        return dp[x][y][z];
    }

    double result = N + x*dfs(x-1, y, z) + y*dfs(x+1, y-1, z) + z*dfs(x, y+1, z-1);
    dp[x][y][z] = result / (x+y+z);

    return dp[x][y][z];
}

int main()
{
    cin >> N;

    int count[4];
    memset(count, 0, sizeof count);

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        count[a]++;
    }

    memset(dp, 0, sizeof dp);

    cout << fixed << setprecision(10) << dfs(count[1], count[2], count[3]) << endl;

    return 0;
}
