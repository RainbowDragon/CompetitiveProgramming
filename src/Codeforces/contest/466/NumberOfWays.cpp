/**
 *      Codeforces Round #266 (Div. 2) - C. Number of Ways
 *
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    int a[n];
    ll prefixSum[n+1];
    prefixSum[0] = 0;
    unordered_map<ll, ll> sumCount;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prefixSum[i+1] = prefixSum[i] + a[i];
        sumCount[prefixSum[i+1]]++;
    }

    ll result = 0;    
    if (prefixSum[n] % 3 == 0) {
        for (int i = n; i > 1; i--)
        {
            ll last = prefixSum[n] - prefixSum[i-1];
            sumCount[prefixSum[i]]--;
            if (prefixSum[i-1] == last*2) {
                result += (last == 0) ? sumCount[last]-1 : sumCount[last];
            }
        }
    }
    cout << result << endl;

    return 0;
}
