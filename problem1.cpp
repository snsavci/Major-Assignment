#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a meeting
struct Meeting {
    int start;
    int end;
};

// Comparison function for sorting meetings by end time
bool compareMeetings(const Meeting& m1, const Meeting& m2) {
    return m1.end < m2.end;
}

// Function to find the maximum number of meetings
int maxMeetings(int start[], int end[], int n) {
    // Create an array of meetings
    vector<Meeting> meetings(n);
    for (int i = 0; i < n; ++i) {
        meetings[i] = { start[i], end[i] };
    }

    // Sort meetings by end time
    sort(meetings.begin(), meetings.end(), compareMeetings);

    // Initialize variables
    int count = 1;
    int last_finish_time = meetings[0].end;

    // Iterate through meetings and check for overlap
    for (int i = 1; i < n; ++i) {
        if (meetings[i].start >= last_finish_time) {
            count++;
            last_finish_time = meetings[i].end;
        }
    }

    return count;
}

int main() {
    // Predefined start and end times for meetings
    int n = 6; // Number of meetings
    int start[] = { 1, 3, 0, 5, 8, 5 };
    int end[] = { 2, 4, 6, 7, 9, 9 };

    int max_meetings = maxMeetings(start, end, n);

    cout << "Start Times\t\t\t: ";
    for (int i = 0; i < n; ++i) {
        cout << start[i] << " ";
    }
    cout << endl;

    cout << "End Times\t\t\t: ";
    for (int i = 0; i < n; ++i) {
        cout << end[i] << " ";
    }
    cout << endl;

    cout << "Maximum number of meetings \t: " << max_meetings << endl;

    return 0;
}
