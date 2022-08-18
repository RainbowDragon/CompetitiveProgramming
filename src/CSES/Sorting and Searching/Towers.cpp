/**
 *      CSES Problem Set - Towers
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int k[n];
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    
    map<int, int> myMap;
    for (int i = 0; i < n; i++)
    {
        auto it = myMap.upper_bound(k[i]);
        if (it == myMap.end()) {
            myMap[k[i]]++;
        }
        else {
            myMap[k[i]]++;
            (*it).second--;
            if ((*it).second == 0) {
                myMap.erase((*it).first);
            }
        }
    }

    int result = 0;
    for (auto p : myMap)
    {
        result += p.second;
    }

    cout << result << endl;
    
    return 0;
}
