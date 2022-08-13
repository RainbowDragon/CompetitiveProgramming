/**
 *      CSES Problem Set - Bit Strings
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

int main()
{
    int n;
    cin >> n;
    
    ll result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= 2;
        result %= MOD;
    }

    cout << result << endl;

    return 0;
}
