/**
 *      Codeforces Round #266 (Div. 2) - A. Cheap Travel
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int result = n * a;

    if (b < m*a) {

        result = (n / m)*b;
        result += min((n % m)*a, b);
    }

    cout << result << endl;

    return 0;
}
