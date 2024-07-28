#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<pii> q;
        vector<int> minimum(n + 1, -1);
        vector<int> second_minimum(n + 1, -1);
        q.push({1, 1});
        minimum[1] = 0;

        while (!q.empty()) {
            pii front = q.front();
            int node = front.first;
            int freq = front.second;
            q.pop();
            int timeTaken = freq == 1 ? minimum[node] : second_minimum[node];
            if ((timeTaken / change) % 2) {
                timeTaken = change * (timeTaken / change + 1) + time;
            } else {
                timeTaken = timeTaken + time;
            }
            for (int& neighbor : adj[node]) {
                if (minimum[neighbor] == -1) {
                    minimum[neighbor] = timeTaken;
                    q.push({neighbor, 1});
                } else if (second_minimum[neighbor] == -1 && minimum[neighbor] != timeTaken) {
                    if (neighbor == n) {
                        return timeTaken;
                    }
                    second_minimum[neighbor] = timeTaken;
                    q.push({neighbor, 2});
                }
            }
        }
        return 0;
    }
int main() {
	cout<<"hello"<<endl;
	vector<vector<int>> edges = {{1,2},{1,3},{1,4},{3,4},{4,5}};
	int time = 3;
	int change = 5;
	int ans = secondMinimum(5, edges, time, change);
	cout<<ans<<endl;
	return 1;
}