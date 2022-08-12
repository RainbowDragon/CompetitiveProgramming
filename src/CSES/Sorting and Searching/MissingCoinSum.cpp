/**
 *      CSES Problem Set - Missing Coin Sum
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    int coin[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    sort(coin, coin+n);

    ll sum = 0;
    for (int x : coin) 
    {
        if (sum+1 < x) {
            cout << sum+1 << endl;
            return 0;
        }
        else {
            sum += x;
        }
    }

    cout << sum+1 << endl;

    return 0;
}
