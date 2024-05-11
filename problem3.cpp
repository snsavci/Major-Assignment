#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparison function for sorting jobs by deadline (ascending) and profit (descending)
bool compareJobs(const Job& j1, const Job& j2) {
    if (j1.deadline != j2.deadline) {
        return j1.deadline < j2.deadline; // Sort by deadline first
    }
    else {
        return j1.profit > j2.profit; // Then sort by profit in descending order
    }
}

// Function to find the maximum profit and number of jobs scheduled using dynamic programming
pair<int, vector<int>> JobSchedulingDP(Job jobs[], int n) {
    // Sort jobs by deadline and profit
    sort(jobs, jobs + n, compareJobs);

    // Allocate memory for the DP table (dp[i] stores the maximum profit achievable considering jobs up to deadline i)
    int* dp = new int[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = 0;
    }

    // Track jobs included in the schedule using a separate vector
    vector<int> included_jobs;

    // Iterate through jobs in sorted order
    for (int i = 0; i < n; ++i) {
        // Find the latest possible slot for the current job based on its deadline
        int latest_slot = min(jobs[i].deadline, n);

        // Update dp value for the current slot (consider including the current job)
        dp[latest_slot] = max(dp[latest_slot], dp[latest_slot - 1] + jobs[i].profit);

        // Track the included job if it contributes to the maximum profit
        if (dp[latest_slot] > dp[latest_slot - 1]) {
            included_jobs.push_back(i);
        }
    }

    // Maximum profit is stored in the last element of the DP table
    int max_profit = dp[n];

    // Deallocate memory for the DP table
    delete[] dp;

    return { max_profit, included_jobs };
}

int main() {
    // Predefine the number of jobs (n)
    int n = 4;

    // Predefined jobs with ID, Deadline, and Profit
    Job jobs[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };

    pair<int, vector<int>> result = JobSchedulingDP(jobs, n);
    int max_profit = result.first;
    vector<int> included_jobs = result.second;

    cout << "Jobs included (ID, Deadline, Profit):" << endl;
    for (int i = 0; i < included_jobs.size(); ++i) {
        cout << jobs[included_jobs[i]].id << " " << jobs[included_jobs[i]].deadline << " " << jobs[included_jobs[i]].profit << endl;
    }

    cout << endl<<"Maximum profit using DP: " << max_profit << endl;

    cout << "Number of jobs included: " << included_jobs.size() << endl;



    return 0;
}
