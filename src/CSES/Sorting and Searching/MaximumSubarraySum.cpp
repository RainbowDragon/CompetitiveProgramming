/**
 *      CSES Problem Set - Maximum Subarray Sum
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    
    ll result = x[0];
    ll last = x[0];
    for (int i = 1; i < n; i++)
    {
        last = last > 0 ? last+x[i] : x[i];
        result = max(result, last);
    }

    cout << result << endl;

    return 0;
}
