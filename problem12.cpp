#include <iostream>
#include <vector>
using namespace std;

int numberSequence(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize dp[i][1] as 1
    for (int i = 1; i <= m; i++) {
        dp[i][1] = 1;
    }

    // Fill dp using bottom-up dynamic programming
    for (int j = 2; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            for (int k = 1; k <= i / 2; k++) {
                dp[i][j] += dp[k][j - 1];
            }
        }
    }

    // Sum up all dp[i][n] for i from 1 to m
    int total = 0;
    for (int i = 1; i <= m; i++) {
        total += dp[i][n];
    }

    return total;
}

int main() {
    cout << numberSequence(10, 4) << endl; // Output: 4
    cout << numberSequence(5, 2) << endl;  // Output: 6

    return 0;
}
