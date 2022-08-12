/**
 *      CSES Problem Set - Increasing Array
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    
    ll result = 0;
    int last = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x < last) {
            result += (last - x);
        }
        else {
            last = x;
        }
    }

    cout << result << endl;

    return 0;
}
