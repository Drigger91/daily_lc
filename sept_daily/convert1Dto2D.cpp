#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if (m * n != original.size()) return {};
    if (m == 1) {
        return {original};
    }
    vector<vector<int>> ans(m, vector<int>(n));
    int i = 0;
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            ans[row][col] = original[i++];
        }
    }
    return ans;
}
int main(int argc, char const *argv[]) {
	vector<int> arr = {1,2,3,4};
	vector<vector<int>> ans = construct2DArray(arr, 2, 2);

	for (vector<int>& a : ans) {
		for (int i : a) cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}