/**
 *      CSES Problem Set - Apartments
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);

    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(b, b+m);

    int result = 0;
    int pn = 0;
    int pm = 0;
    while (pn < n && pm < m)
    {
        if (a[pn]-k <= b[pm] && b[pm] <= a[pn]+k) {
            result++;
            pn++;
            pm++;
        }
        else {
            if (a[pn] < b[pm]) {
                pn++;
            }
            else {
                pm++;
            }
        }
    }

    cout << result << endl;

    return 0;
}
