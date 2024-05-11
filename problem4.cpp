#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a pair
struct Pair {
    int first;
    int second;
};

// Comparison function for sorting pairs by their first element (ascending)
bool comparePairs(const Pair& p1, const Pair& p2) {
    return p1.first < p2.first;
}

// Function to find the longest chain of pairs using a greedy approach
int maxChainLen(Pair arr[], int n) {
    // Sort pairs by their first element
    sort(arr, arr + n, comparePairs);

    // Initialize variables to track the chain length
    int max_chain_len = 1;
    int prev_second = arr[0].second; // Store the second element of the previous pair

    // Iterate through the sorted pairs
    for (int i = 1; i < n; ++i) {
        // Check if the current pair's first element is greater than the previous pair's second element
        if (arr[i].first > prev_second) {
            max_chain_len++;
            prev_second = arr[i].second; // Update the previous second element
        }
    }

    return max_chain_len;
}

// Function to print the contents of the Pair arr array
void printPairs(Pair arr[], int n) {
    cout << "Pairs (first, second):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "(" << arr[i].first << ", " << arr[i].second << ")" << endl;
    }
}

int main() {
    // Predefined pairs (replace with actual data if needed)
    int n = 5;
    Pair arr[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };

    // Print the pairs before sorting
    printPairs(arr, n);

    int max_chain_length = maxChainLen(arr, n);

    // Print the pairs after sorting (optional)
    // printPairs(arr, n);

    cout << "Maximum length of chain: " << max_chain_length << endl;

    return 0;
}
