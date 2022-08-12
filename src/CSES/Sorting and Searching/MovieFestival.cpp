/**
 *      CSES Problem Set - Movie Festival
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    pair<int, int> movie[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        movie[i] = {b, a};
    }
    sort(movie, movie+n);

    int result = 1;
    int endTime = movie[0].first;
    for (int i = 1; i < n; i++)
    {
        if (movie[i].second >= endTime) {
            result++;
            endTime = movie[i].first;
        }
    }

    cout << result << endl;

    return 0;
}
