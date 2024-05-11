#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first;
    int second;
};

void printPairs(const vector<Pair>& pairs, int n) {
    cout << "Pairs in the longest chain: ";
    for (int i = 0; i < n; i++) {
        if (i > 0 && pairs[i - 1].second != pairs[i].first)
            cout << ", ";
        cout << "(" << pairs[i].first << ", " << pairs[i].second << ")";
    }
    cout << endl;
}

int maxChainLen(vector<Pair>& pairs, int n) {
    // Sort the pairs based on the second element of each pair
    sort(pairs.begin(), pairs.end(), [](const Pair& a, const Pair& b) {
        return a.second < b.second;
        });

    // Initialize a dynamic programming table to store the length of the longest chain ending at each pair
    vector<int> dp(n, 1);

    int maxLen = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (pairs[i].first > pairs[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    printPairs(pairs, n);
    return maxLen;
}

int main() {
    vector<Pair> pairs = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n = pairs.size();

    int maxLength = maxChainLen(pairs, n);

    cout << "Length of the longest chain: " << maxLength << endl;

    return 0;
}