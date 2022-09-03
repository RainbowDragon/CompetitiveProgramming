/**
 *      CSES Problem Set - Tasks and Deadlines
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
    ll result = 0;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> a[i] >> d;
        result += d;
    }
    sort(a, a+n);

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        result -= sum;
    }

    cout << result << endl;
    
    return 0;
}
