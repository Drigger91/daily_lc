
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int rangeSum(vector<int>& nums, int n, int left, int right) {
	vector<int> sums;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < nums.size(); j++) {
			sum += nums[j];
			sums.push_back(sum);
		}
	}
	sort(sums.begin(), sums.end());
	int ans = 0;
	for (int i = left - 1; i < right; i++) {
		ans += (sums[i]) % mod;
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	vector<int> nums = {1,2,3,4};
	int left = 1;
	int right = 5;
	cout<< "Ans is : "<<rangeSum(nums, 4, left, right)<<endl;
	return 0;
}