#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if a cell is within board boundaries
bool isValid(int row, int col, int m, int n) {
    return (row >= 0 && row < m && col >= 0 && col < n);
}

// Recursive function to find all words in the board using backtracking
void findWordsUtil(vector<vector<char>>& board, int row, int col, set<string>& words,
    string currentWord, vector<vector<bool>>& visited, const vector<string>& dictionary) {
    // Base case: reached the end of a valid word
    if (find(dictionary.begin(), dictionary.end(), currentWord) != dictionary.end()) {
        words.insert(currentWord); // Add word to the result set
    }

    // Mark the current cell as visited (avoid revisiting)
    visited[row][col] = true;

    // Explore all 8 adjacent cells
    int directions[8][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
    for (int i = 0; i < 8; ++i) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (isValid(newRow, newCol, board.size(), board[0].size()) && !visited[newRow][newCol]) {
            char newChar = board[newRow][newCol];
            findWordsUtil(board, newRow, newCol, words, currentWord + newChar, visited, dictionary);
        }
    }

    // Backtrack: unmark the cell for other paths
    visited[row][col] = false;
}

// Function to find all words in the board
set<string> wordBoggle(vector<vector<char>>& board, const vector<string>& dictionary) {
    int m = board.size();
    int n = board[0].size();
    set<string> words;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // Explore all cells in the board
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            string currentWord = "";
            findWordsUtil(board, i, j, words, currentWord, visited, dictionary);
        }
    }

    return words; // Return the set of found words
}

int main() {
    // Predefined board and dictionary (replace with actual data if needed)
    vector<vector<char>> board = { {'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'} };
    vector<string> dictionary = { "GEEKS", "FOR", "QUIZ", "GO" };

    set<string> words = wordBoggle(board, dictionary);

    for (string word : words) {
        cout << word << endl;
    }

    return 0;
}
