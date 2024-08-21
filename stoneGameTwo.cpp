#include<bits/stdc++.h>
using namespace std;

int recursion(vector<int>& nums, int M, int i, vector<vector<int>>& dp) {
    if (i >= nums.size()) return 0;
    
    int total = 0;
    int ans = -1e9;
    if (dp[i][M] != -1) return dp[i][M];
    for (int j = 0; j < 2*M; j++) {
        if (i + j < nums.size()) {
            total += nums[i + j];
        }
        ans = max(ans, total - recursion(nums, max(M, j + 1), i + j + 1, dp));
    }
    return dp[i][M] = ans;
}
int stoneGameII(vector<int>& piles) {
    int sum = 0;
    for (int i : piles) sum += i;
    vector<vector<int>> dp(101, vector<int>(202, -1));
    int difference = recursion(piles, 1, 0, dp);
    
    return (sum + difference)/2;
}
int main(int argc, char const *argv[]) {
	vector<int> check = {1,2,3,4,5,100};
	int ans = stoneGameII(check);

	cout<<"Ans is: "<<ans<<endl;
	return 0;

}