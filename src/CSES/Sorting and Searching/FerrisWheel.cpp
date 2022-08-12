/**
 *      CSES Problem Set - Ferris Wheel
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p, p+n);

    int result = 0;
    int first = 0;
    int last = n-1;
    while (first < last)
    {
        if (p[first] + p[last] <= x) {
            first++;
        }
        result++;
        last--;
    }

    if (first == last) {
        result++;
    }

    cout << result << endl;

    return 0;
}
