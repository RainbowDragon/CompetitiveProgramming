/**
 *      AtCoder Educational DP Contest - E. Knapsack 2
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int NV = 1e5+1;
const ll NW = 1e11+1;

int main()
{
    int N, W;
    cin >> N >> W;
    int weight[N], value[N];
    ll dp[NV];

    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }

    for (int i = 0; i < NV; i++)
    {
        dp[i] = NW;
    }

    dp[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = NV-1; j >= 0; j--)
        {
            if (j >= value[i]) {
                dp[j] = min(dp[j], dp[j-value[i]]+weight[i]);
            }
        }
    }

    for (int i = NV-1; i >= 0; i--)
    {
        if (dp[i] <= W) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
