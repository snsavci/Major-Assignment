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

// Function to find the maximum profit and number of jobs scheduled
vector<int> JobScheduling(Job jobs[], int n) {
    // Sort jobs by deadline and profit
    sort(jobs, jobs + n, compareJobs);

    // Initialize variables
    int count = 0;
    int max_profit = 0;
    int last_finished = 0; // Keep track of the last completed deadline

    // Iterate through sorted jobs
    for (int i = 0; i < n; ++i) {
        if (jobs[i].deadline >= last_finished + 1) { // Check if job can be completed by deadline
            count++;
            last_finished = jobs[i].deadline;
            max_profit += jobs[i].profit;
        }
    }

    return { count, max_profit };
}

int main() {
    // Predefined jobs with ID, Deadline, and Profit
    int n = 4;
    Job jobs[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };

    vector<int> result = JobScheduling(jobs, n);

    cout << "Jobs considered (ID, Deadline, Profit):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << jobs[i].id << " " << jobs[i].deadline << " " << jobs[i].profit << endl;
    }

    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;



    return 0;
}
