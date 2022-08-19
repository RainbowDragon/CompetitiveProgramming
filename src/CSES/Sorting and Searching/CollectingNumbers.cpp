/**
 *      CSES Problem Set - Collecting Numbers
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;

    pii p[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        p[i] = {x, i};
    }
    sort(p, p+n);

    int result = 1;
    for (int i = 1; i < n; i++)
    {
        if (p[i].second < p[i-1].second) {
            result++;
        }
    }

    cout << result << endl;
    
    return 0;
}
