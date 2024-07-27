#include <bits/stdc++.h>
using namespace std;

long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long>> finalCost (26, vector<long>(26, INT_MAX));

        for (int i = 0; i < original.size(); i++) {
                int v = changed[i] - 'a';
                int u = original[i] - 'a';
                finalCost[u][v] = min(finalCost[u][v], (long) cost[i]);
        }

        long long ans = 0;
        for (int node = 0; node < 26; node++) {
                for (int i = 0; i < 26; i++) {
                        for (int j = 0; j < 26; j++) {
                                finalCost[i][j] = min(finalCost[i][j], finalCost[i][node] + finalCost[node][j]);
                        }
                }
        }
        for (int i = 0; i < source.size(); i++) {
                if (source[i] == target[i]) continue;
                int source_char = source[i] - 'a';
                int target_char = target[i] - 'a';
                if (finalCost[source_char][target_char] >= INT_MAX) return -1;

                ans += finalCost[source_char][target_char];
        }
        return ans;
}
int main() {
        cout<<"Hello"<<endl;
        return 0;
}