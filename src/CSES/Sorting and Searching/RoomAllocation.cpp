/**
 *      CSES Problem Set - Room Allocation
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> tiii;

int main()
{
    int n;
    cin >> n;

    tiii day[2*n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        day[2*i] = {a, 0, i};
        day[2*i+1] = {b, 1, i};
    }
    sort(day, day+2*n);

    int result = 0;
    int current = 0;
    int counter = 1;
    int room[n];
    queue<int> q;
    for (int i = 0; i < 2*n; i++)
    {
        if (get<1>(day[i]) == 1) {
            q.push(room[get<2>(day[i])]);
            current--;
        }
        else {
            if (q.empty()) {
                room[get<2>(day[i])] = counter;
                counter++;
            }
            else {
                room[get<2>(day[i])] = q.front();
                q.pop();
            }
            current++;
        }

        result = max(result, current);
    }

    cout << result << endl;

    for (int i = 0; i < n; i++)
    {
        cout << room[i] << " ";
    }
    cout << endl;

    return 0;
}
