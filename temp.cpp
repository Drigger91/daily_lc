#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to perform DFS and find all suspicious methods
void dfs(int node, const vector<vector<int>>& graph, unordered_set<int>& suspicious) {
    if (suspicious.count(node)) return;
    suspicious.insert(node);
    for (int neighbor : graph[node]) {
        if (!suspicious.count(neighbor)) {
            dfs(neighbor, graph, suspicious);
        }
    }
}

// Main function to remove suspicious methods
vector<int> remove_suspicious_methods(int n, int k, const vector<vector<int>>& invocations) {
    // Build the graph
    vector<vector<int>> graph(n);
    for (const auto& edge : invocations) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
    }

    // Find all suspicious methods
    unordered_set<int> suspicious;
    dfs(k, graph, suspicious);

    // Check for methods outside suspicious set invoking methods inside it
    bool cannot_remove = false;
    for (const auto& edge : invocations) {
        int u = edge[0];
        int v = edge[1];
        if (suspicious.count(v) && !suspicious.count(u)) {
            cannot_remove = true;
            break;
        }
    }

    vector<int> result;
    if (cannot_remove) {
        // Cannot remove suspicious methods, return all methods
        for (int i = 0; i < n; ++i) {
            result.push_back(i);
        }
    } else {
        // Return remaining methods after removing suspicious ones
        for (int i = 0; i < n; ++i) {
            if (!suspicious.count(i)) {
                result.push_back(i);
            }
        }
    }

    return result;
}

// Helper function to print the result
void print_methods(const vector<int>& methods) {
    for (int method : methods) {
        cout << method << " ";
    }
    cout << endl;
}

// Main function with test cases
int main() {
    // Example 1
    int n1 = 4;
    int k1 = 1;
    vector<vector<int>> invocations1 = {{1, 2}, {0, 1}, {3, 2}};
    vector<int> result1 = remove_suspicious_methods(n1, k1, invocations1);
    print_methods(result1);  // Output: 0 1 2 3

    // Example 2
    int n2 = 5;
    int k2 = 0;
    vector<vector<int>> invocations2 = {{1, 2}, {0, 2}, {0, 1}, {3, 4}};
    vector<int> result2 = remove_suspicious_methods(n2, k2, invocations2);
    print_methods(result2);  // Output: 3 4

    // Example 3
    int n3 = 3;
    int k3 = 2;
    vector<vector<int>> invocations3 = {{1, 2}, {0, 1}, {2, 0}};
    vector<int> result3 = remove_suspicious_methods(n3, k3, invocations3);
    print_methods(result3);  // Output:

    return 0;
}
