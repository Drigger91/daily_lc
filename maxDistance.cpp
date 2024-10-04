#include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>>& arrays) {
    int ans = 0;
    int mini = arrays[0][0];
    int maxi = arrays[0].back();
    for (int i = 1; i < arrays.size(); i++) {
        ans = max({ans, abs(arrays[i][0] - maxi), abs(arrays[i].back() - mini)});
        mini = min(arrays[i][0], mini);
        maxi = max(arrays[i].back(), maxi);
    }
    return ans;
}

int main(int argc, char const *argv[]) {
	/* 0*/
	vector<vector<int>> check = {{1,0}, {4,5}};

	cout<<"Ans is "<< maxDistance(check);
	return 0;
}