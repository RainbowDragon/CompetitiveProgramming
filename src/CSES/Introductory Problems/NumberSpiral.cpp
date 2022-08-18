/**
 *      CSES Problem Set - Number Spiral
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(int x, int y) 
{
    ll result = 0;
    if (x > y) {
        if (x % 2 == 0) {
            result = x - 1;
            result = result*result + y;
        }
        else {
            result = x;
            result = result*result - y + 1;
        }
    }
    else {
        if (y % 2 == 0) {
            result = y;
            result = result*result - x + 1;
        }
        else {
            result = y - 1;
            result = result*result + x;
        }
    }

    return result;
}

int main()
{
    int t;
    cin >> t;
    
    ll result[t];

    for (int i = 0; i < t; i++)
    {
        int y, x;
        cin >> y >> x;
        result[i] = solve(x, y);
    }

    for (int i = 0; i < t; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}
