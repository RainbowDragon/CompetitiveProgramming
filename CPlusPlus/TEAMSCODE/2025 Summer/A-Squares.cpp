/**
 *      TEAMSCODE - Summer 2025 - A. Squares
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;

    vector<ll> x1(N), y1(N), x2(N), y2(N);

    for (int i = 0; i < N; i++)
    {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    ll X1 = x1[0];
    ll Y1 = y1[0];
    ll X2 = x2[0];
    ll Y2 = y2[0];    

    for (int i = 0; i < N; i++)
    {
        X1 = min(X1, x1[i]);
        Y1 = min(Y1, y1[i]);
        X2 = max(X2, x2[i]);
        Y2 = max(Y2, y2[i]);
    }

    cout << min(X1, Y1) << " " << min(X1, Y1) << " " << max(X2, Y2) << " " << max(X2, Y2) << endl;

    return 0;
}