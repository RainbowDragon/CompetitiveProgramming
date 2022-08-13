/**
 *      CSES Problem Set - Two Knights
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    
    ll result[n+1];
    for (ll i = 1; i <= n; i++)
    {
        result[i] = i*i*(i*i-1)/2 - 4*(i-1)*(i-2); 
    }

    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}
