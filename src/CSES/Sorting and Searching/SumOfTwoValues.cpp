/**
 *      CSES Problem Set - Sum of Two Values
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int a[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    map<int, int> myMap;

    for (int i = 1; i <= n; i++)
    {
        if (myMap.find(x-a[i]) != myMap.end()) {
            cout << myMap[x-a[i]] << " " << i << endl;
            return 0;
        }
        else {
            myMap[a[i]] = i;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
