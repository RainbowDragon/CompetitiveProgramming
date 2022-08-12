/**
 *      CSES Problem Set - Permutations
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl;
    }
    else if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
    }
    else {
        int half = n / 2;
        int extra = (n % 2 == 0) ? 0 : 1;

        for (int i = 1; i <= half; i++)
        {
            cout << half+i+extra << " " << i+extra << " ";
        }

        if (n % 2 != 0) {
            cout << 1;
        }

        cout << endl;
    }

    return 0;
}
