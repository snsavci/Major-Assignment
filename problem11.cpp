#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if a book allocation is valid (all students get at least one book)
bool isValid(vector<int>& pages, int n, int m, int curr_min) {
    int student = 1;
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += pages[i];

        // If the sum exceeds the current minimum or we need another student
        if (sum > curr_min || (student < m && i + 1 != n)) {
            student++;
            sum = pages[i];
        }
    }

    return student == m; // Check if all students have books
}

// Binary search function to find the minimum sum of maximum pages
int findPages(vector<int>& pages, int n, int m) {
    sort(pages.begin(), pages.end()); // Sort the pages array

    int min_sum = pages[n - 1]; // Initialize with maximum page value
    int max_sum = 0;         // Initialize with sum of all pages

    // Find minimum and maximum possible sums
    for (int page : pages) {
        max_sum += page;
    }

    int result = -1;

    // Binary search to find the minimum valid sum
    while (min_sum <= max_sum) {
        int mid = min_sum + (max_sum - min_sum) / 2;

        // Check if the current allocation is valid
        if (isValid(pages, n, m, mid)) {
            result = mid;
            max_sum = mid - 1; // Reduce search space to left side (lower sums)
        }
        else {
            min_sum = mid + 1; // Increase search space to right side (higher sums)
        }
    }

    return result;
}

int main() {
    // Predefined data (replace with actual data if needed)
    vector<int> pages = { 12, 34, 67, 90 };
    int n = pages.size();
    int m = 2;

    int min_pages = findPages(pages, n, m);

    if (min_pages == -1) {
        cout << "Invalid allocation" << endl;
    }
    else {
        cout << min_pages << endl;
    }

    return 0;
}
