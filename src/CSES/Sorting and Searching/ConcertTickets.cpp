/**
 *      CSES Problem Set - Concert Tickets
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    map<int, int> myMap;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        if (myMap.find(h) != myMap.end()) {
            myMap[h]++;
        }
        else {
            myMap[h] = 1;
        }
    }

    int T[m];
    for (int i = 0; i < m; i++)
    {
        cin >> T[i];
    }

    int result[m];
    for (int i = 0; i < m; i++)
    {
        auto it = myMap.lower_bound(T[i]);
        if (it == myMap.begin() && (*it).first != T[i]) {
            result[i] = -1;
        }
        else {
            if ((*it).first != T[i]) {
                it--;
            }
            result[i] = (*it).first;
            (*it).second--;
            if ((*it).second == 0) {
                myMap.erase((*it).first);
            }
        }
    }    

    for (int i = 0; i < m; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}
