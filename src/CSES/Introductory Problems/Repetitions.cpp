/**
 *      CSES Problem Set - Repetitions
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    
    int result = 0;

    char last = '#';
    int count = 0;

    for (char c : str)
    {
        if (last == c) {
            count++;
        }
        else {
            last = c;
            count = 1;
        }
        result = max(result, count);
    }

    cout << result << endl;

    return 0;
}
