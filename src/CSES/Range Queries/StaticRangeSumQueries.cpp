/**
 *      CSES Problem Set - Static Range Sum Queries
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, q;
    cin >> n >> q;

    ll prefixSum[n+1];
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> prefixSum[i];
        prefixSum[i] += prefixSum[i-1];
    }

    ll result[q];
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        result[i] = prefixSum[b] - prefixSum[a-1];
    }

    for (int i = 0; i < q; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}
