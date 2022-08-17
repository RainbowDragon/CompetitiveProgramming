/**
 *      CSES Problem Set - Stick Lengths
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    int stick[n];
    for (int i = 0; i < n; i++)
    {
        cin >> stick[i];
    }
    sort(stick, stick+n);
    int middle = n / 2;

    ll result = 0;
    for (int i = 0; i < n; i++)
    {
        result += abs(stick[i] - stick[middle]);
    }

    cout << result << endl;

    return 0;
}
