/**
 *      CSES Problem Set - Traffic Lights
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;

    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    
    map<int, int> position;
    map<int, int> length;
    position[x] = x;
    length[x] = 1;

    int result[n];
    for (int i = 0; i < n; i++)
    {
        auto it = position.upper_bound(p[i]);
        int len = (*it).second;
        int len1 = (*it).first - p[i];
        (*it).second = len1;
        position[p[i]] = len - len1;

        length[len]--;
        if (length[len] == 0) {
            length.erase(len);
        }
        length[len1]++;
        length[len-len1]++;

        auto last = length.rbegin();
        result[i] = (*last).first;
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
