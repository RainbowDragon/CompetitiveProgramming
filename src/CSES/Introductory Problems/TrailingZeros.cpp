/**
 *      CSES Problem Set - Trailing Zeros
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int result = 0;
    while (n > 0)
    {
        result += (n / 5);
        n /= 5;
    }

    cout << result << endl;

    return 0;
}
