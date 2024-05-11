#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, vector<vector<int>>& graph, vector<int>& color, int col) {
    for (int neighbor = 0; neighbor < graph.size(); neighbor++) {
        if (graph[node][neighbor] == 1 && color[neighbor] == col)
            return false;
    }
    return true;
}

bool graphColoringUtil(int node, vector<vector<int>>& graph, int m, vector<int>& color) {
    if (node == graph.size())
        return true;

    for (int col = 1; col <= m; col++) {
        if (isSafe(node, graph, color, col)) {
            color[node] = col;
            if (graphColoringUtil(node + 1, graph, m, color))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m, int n) {
    vector<int> color(n, 0); // Initialize all vertices with color 0
    if (graphColoringUtil(0, graph, m, color)) {
        cout << "1\n"; // Solution exists
        return true;
    }
    else {
        cout << "0\n"; // Solution doesn't exist
        return false;
    }
}

int main() {
    int n1 = 4, m1 = 3;
    vector<vector<int>> graph1 = { {0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0} };
    graphColoring(graph1, m1, n1);

    int n2 = 3, m2 = 2;
    vector<vector<int>> graph2 = { {0, 1, 1}, {1, 0, 1}, {1, 1, 0} };
    graphColoring(graph2, m2, n2);

    return 0;
}
