/**
 *      AtCoder Educational DP Contest - J. Sushi
 *
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int count[4] = {0};
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        count[a]++;
    }

    // dp[i][j][k] stores the expected number of moves when there are:
    // i dishes with 1 coin
    // j dishes with 2 coins
    // k dishes with 3 coins
    double dp[N+1][N+1][N+1];

    // Iterating bottom-up based on total number of coins
    for (int k = 0; k <= N; k++) {
        for (int j = 0; j <= N; j++) {
            for (int i = 0; i <= N; i++) {
                
                // Base case: 0 coins left means 0 expected moves
                if (i == 0 && j == 0 && k == 0) {
                    dp[i][j][k] = 0.0;
                    continue;
                }
                
                // We cannot have more total items than N
                if (i + j + k > N) continue;

                double total_active = i + j + k;
                
                // Transition components
                double choose_1 = (i > 0) ? i * dp[i - 1][j][k] : 0.0;
                double choose_2 = (j > 0) ? j * dp[i + 1][j - 1][k] : 0.0;
                double choose_3 = (k > 0) ? k * dp[i][j + 1][k - 1] : 0.0;

                // Derived from the equation:
                dp[i][j][k] = (N + choose_1 + choose_2 + choose_3) / total_active;
            }
        }
    }

    // Print the final result calculated for our initial counts
    cout << fixed << setprecision(10) << dp[count[1]][count[2]][count[3]] << endl;

    return 0;
}