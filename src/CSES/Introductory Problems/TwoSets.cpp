/**
 *      CSES Problem Set - Two Sets
 *
 */

#include <bits/stdc++.h>

using namespace std;

void print(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    
    int sum = n*(n+1)/2;

    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    if (n % 2 == 0) {
        int left[n/2];
        int right[n/2];
        for (int i = 0; i < n/4; i++)
        {
            left[2*i] = 1 + 4*i;
            left[2*i+1] = 4 + 4*i;
            right[2*i] = 2 + 4*i;
            right[2*i+1] = 3 + 4*i;
        }

        cout << n/2 << endl;
        print(left, n/2);
        cout << n/2 << endl;
        print(right, n/2);
    }
    else {
        int left[n/2+1];
        int right[n/2];
        left[0] = 1;
        left[1] = 2;
        right[0] = 3;
        for (int i = 0; i < n/4; i++)
        {
            left[2+2*i] = 4 + 4*i;
            left[2+2*i+1] = 7 + 4*i;
            right[1+2*i] = 5 + 4*i;
            right[1+2*i+1] = 6 + 4*i;
        }

        cout << n/2+1 << endl;
        print(left, n/2+1);
        cout << n/2 << endl;
        print(right, n/2);        
    }

    return 0;
}
