#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to check if a string represents a valid IP segment (0-255, no leading zeros except 0)
bool isValidSegment(string segment) {
    if (segment.empty() || segment.length() > 3) {
        return false;
    }

    // Check if the first character is 0 (except for "0")
    if (segment[0] == '0' && segment.length() > 1) {
        return false;
    }

    int value;
    stringstream ss(segment);
    ss >> value;

    return (value >= 0 && value <= 255);
}

// Recursive function to generate all possible IP addresses using backtracking
void generateIp(string str, int dots, string currentIp, vector<string>& ips) {
    // Base case: reached the end of the string with 3 dots (valid IP)
    if (dots == 3 && str.empty()) {
        ips.push_back(currentIp);
        return;
    }

    // Base cases: invalid scenario (too many dots, string too long for remaining segments)
    if (dots > 3 || str.length() > (4 - dots) * 3) {
        return;
    }

    // Try all possible segment lengths (1, 2, or 3 characters)
    for (int i = 1; i <= 3 && i <= str.length(); ++i) {
        string segment = str.substr(0, i);

        // Check if the segment is valid and recursively explore possibilities
        if (isValidSegment(segment)) {
            string newIp = currentIp.empty() ? segment : currentIp + "." + segment;
            generateIp(str.substr(i), dots + 1, newIp, ips);
        }
    }
}

// Function to generate all possible valid IPv4 addresses
vector<string> genIp(string S) {
    vector<string> ips;
    generateIp(S, 0, "", ips);

    if (ips.empty()) {
        return vector<string> {"-1"}; // No valid IP addresses found
    }

    return ips;
}

int main() {
    // Predefined string (replace with actual data if needed)
    string S = "11211";

    vector<string> ips = genIp(S);

    if (ips[0] == "-1") {
        cout << "-1" << endl; // No valid IP addresses found
    }
    else {
        for (string ip : ips) {
            cout << ip << endl;
        }
    }

    return 0;
}
