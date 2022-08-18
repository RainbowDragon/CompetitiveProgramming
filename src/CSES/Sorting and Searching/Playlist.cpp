/**
 *      CSES Problem Set - Playlist
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
    int result = 1;
    int p1 = 0;
    myMap[k[0]] = 0;

    for (int p2 = 1; p2 < n; p2++)
    {
        if (myMap.find(k[p2]) == myMap.end()) {
            myMap[k[p2]] = p2;
        }
        else {
            for (int j = p1; j < myMap[k[p2]]; j++)
            {
                myMap.erase(k[j]);
            }
            p1 = myMap[k[p2]] + 1;
            myMap[k[p2]] = p2;
        }

        result = max(result, p2-p1+1);
    }

    cout << result << endl;

    return 0;
}
