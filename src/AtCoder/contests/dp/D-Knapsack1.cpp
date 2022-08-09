/**
 *      AtCoder Educational DP Contest - D. Knapsack 1
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int N, W;
    cin >> N >> W;
    int weight[N], value[N];
    ll dp[W+1];

    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }

    for (int i = 0; i <= W; i++)
    {
        dp[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = W; j > 0; j--)
        {
            if (j >= weight[i]) {
                dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
            }
        }
    }

    cout << dp[W] << endl;

    return 0;
}
