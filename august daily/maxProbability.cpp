#include<bits/stdc++.h>
using namespace std;
#define pid pair<int,double>
#define pdi pair<double,int>

double dfs(vector<vector<pid>>& graph, int node, int e, int par, double curr_prob, vector<bool>& vis) {
	if (e == node) {
		return curr_prob;
	}
	if (vis[node]) {
		return 0;
	}
	vis[node] = true;
	double ans = 0;
	for (pid child: graph[node]) {
		int child_node = child.first;
		double edge_prob = child.second;
		if (child_node != par && !vis[child_node]) {
			vis[child_node] = true;
			ans = max(ans, dfs(graph, child_node, e, node, curr_prob * edge_prob, vis));
		}
		vis[child_node] = false;
	}
	return ans;
}
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int s, int e) {
	vector<vector<pdi>> graph(n);
	int i = 0;
	for (vector<int>& edge: edges) {
		int u = edge[0];
		int v = edge[1];
		double curr_prob = prob[i++];
		graph[v].push_back({curr_prob, u});
		graph[u].push_back({curr_prob, v});
	}
	priority_queue<pdi> pq;
	pq.push({1.0, s});
	vector<double> maxProb(n, 0.0);
	//maxProb[s] = 1.0;
	while (!pq.empty()) {
		pdi curr = pq.top();
		double prob = curr.first;
		int node = curr.second;
		pq.pop();
		//cout<<node<<" "<<prob<<endl;
		if (node == e) {
			return prob;
		} 
		for (const pdi& child : graph[node]) {
            double edge_prob = child.first;
            int child_node = child.second;
            if (child_node == node) continue;
            double newProb = prob * edge_prob;
            //cout<<child_node<<" "<<newProb<<endl;
            if (newProb > maxProb[child_node]) {
                maxProb[child_node] = newProb;
                pq.push({newProb, child_node});
            }
        }

	}
	return 0;
}
int main(int argc, char const *argv[]) {
	vector<vector<int>> edges = {{2,3},{1,2},{3,4},{1,3},{1,4},{0,1},{2,4},{0,4},{0,2}};
	vector<double> prob = {0.06,0.26,0.49,0.25,0.2,0.64,0.23,0.21,0.77};
	double ans = maxProbability(5, edges, prob, 0, 3);
	cout<<"Ans is : "<<ans<<endl;
	return 0;
}