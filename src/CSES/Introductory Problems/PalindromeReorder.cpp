/**
 *      CSES Problem Set - Palindrome Reorder
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    
    int count[26];
    memset(count, 0, sizeof count);
    for (char c : str)
    {
        count[c - 'A']++;
    }

    int index = 0;
    int len = str.length();
    int num = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] % 2 != 0) {
            num++;
            if (num > 1) {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
            str[len/2] = 'A' + i;
        }

        char c = 'A' + i;
        int half = count[i] / 2;
        while (half > 0)
        {
            str[index] = c;
            str[len-index-1] = c;
            index++;
            half--;
        }
    }

    cout << str << endl;

    return 0;
}
