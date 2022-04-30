/**
 *      Codeforces Round #266 (Div. 2) - D. Increase Sequence
 *
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int main()
{
    int n, h;
    cin >> n >> h;

    int a[n+2];
    int b[n+1];

    for (int i = 1; i <= n; i++)
    {
        int value;
        cin >> value;
        a[i] = h - value;
    }

    a[0] = a[n+1] = 0;
    for (int i = 1; i <= n+1; i++)
    {
        b[i] = a[i] - a[i-1];
        if (b[i] > 1 || b[i] < -1) {
            cout << 0 << endl;
            return 0;
        }
    }

    ll result = 1;
    for (int i = 1; i <= n+1; i++)
    {
        if (b[i] == 0) {
            result *= a[i] + 1;
        }
        else if (b[i] == -1) {
            result *= a[i-1];
        }
        result %= MOD;
    }

    cout << result << endl;

    return 0;
}
