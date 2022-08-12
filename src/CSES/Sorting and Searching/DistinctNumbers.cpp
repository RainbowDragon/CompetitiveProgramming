/**
 *      CSES Problem Set - Distinct Numbers
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> mySet;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mySet.insert(x);
    }

    cout << mySet.size() << endl;

    return 0;
}
