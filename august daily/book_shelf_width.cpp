#include<bits/stdc++.h>
using namespace std;
int helper(int i, vector<vector<int>>& books, int remainingWidth, vector<int>& dp) {
	if (i >= books.size()) return 0;
	if (dp[i] != -1) return dp[i];
	int ans = INT_MAX;
	int currentMax = 0, currentWidth = 0;
	for (int j = i; j < books.size(); j++) {
		currentWidth += books[j][0];
		if (currentWidth > remainingWidth) return dp[i] = ans;
		currentMax = max(currentMax, books[j][1]);
		int putOnNextShelf = helper(j + 1, books, remainingWidth, dp);
		ans = min((putOnNextShelf >= INT_MAX ? INT_MAX : currentMax + putOnNextShelf), ans);
		// cout<<putOnNextShelf<<endl;
	}
	return dp[i] = ans;
}

int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
	vector<int> dp(books.size(), -1);
	return helper(0, books, shelfWidth, dp);
}
int main() {
	cout<<"Hello"<<endl;
	vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
	int shelfWidth = 4;
	int ans = minHeightShelves(books, shelfWidth);
	cout<<ans<<endl;
	return 1;
}