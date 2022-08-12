/**
 *      CSES Problem Set - Missing Number
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    
    ll sum = ((ll)n) * (n + 1) / 2;

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        sum -= x;
    }

    cout << sum << endl;

    return 0;
}
