#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

// Function to check if a cell is valid (within maze boundaries and not blocked)
bool isValid(vector<vector<int>>& maze, int row, int col, int n) {
    return (row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == 1);
}

// Recursive function to find all possible paths using backtracking
void findPaths(vector<vector<int>>& maze, int row, int col, int n, string& path, vector<string>& paths) {
    // Base case: reached destination
    if (row == n - 1 && col == n - 1) {
        paths.push_back(path);
        return;
    }

    // Mark the current cell as visited (avoid revisiting)
    maze[row][col] = 0;

    // Try all valid moves (up, down, left, right)
    int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    for (int i = 0; i < 4; ++i) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (isValid(maze, newRow, newCol, n)) {
            path.push_back((i == 0) ? 'U' : (i == 1) ? 'D' : (i == 2) ? 'R' : 'L'); // Add direction character to path
            findPaths(maze, newRow, newCol, n, path, paths);
            path.pop_back(); // Backtrack: remove character after exploring the path
        }
    }

    // Unmark the current cell (for other paths)
    maze[row][col] = 1;
}

// Function to print all possible paths (can be replaced with returning the list)
void printPaths(vector<vector<int>>& maze, int n) {
    vector<string> paths;
    string path;
    findPaths(maze, 0, 0, n, path, paths);

    if (paths.empty()) {
        cout << "-1" << endl; // No paths found
    }
    else {
        sort(paths.begin(), paths.end()); // Sort paths lexicographically
        for (string p : paths) {
            cout << p << endl;
        }
    }
}

int main() {
    // Predefined maze (replace with actual data if needed)
    int n = 4;
    vector<vector<int>> maze = { {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };

    printPaths(maze, n);

    return 0;
}
