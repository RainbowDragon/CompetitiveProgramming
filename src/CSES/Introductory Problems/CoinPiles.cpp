/**
 *      CSES Problem Set - Coin Piles
 *
 */

#include <bits/stdc++.h>

using namespace std;

bool test(int a, int b)
{
    if (a == b) {
        return a % 3 == 0;
    }
    else if (b > a) {
        return test(b, a);
    }
    else {
        if (a - b > b) {
            return false;
        }
        else {
            return (2*b-a) % 3 == 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    bool result[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        result[i] = test(a, b);
    }

    for (int i = 0; i < n; i++)
    {
        cout << (result[i] ? "YES" : "NO") << endl;
    }

    return 0;
}
