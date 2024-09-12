#include<bits/stdc++.h>
using namespace std;

// imp :  If no such array exists, return an empty array.

vector<int> solve(int required_sum, int n) {
	if (required_sum < n || required_sum > 6 * n) {
		return {};
	}
	vector<int> ans(n, 1);
	required_sum -= n;
	for (int i = 0; i < n && required_sum > 0; i++) {
		int to_add = min(5, required_sum);
		required_sum -= to_add;
		ans[i] += to_add;
	}
	return ans;
}

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    int total = m + n;
    int desired_sum = mean * total;
    int sum = 0;
    for (int i : rolls) {
    	sum += i;
    }
    int required_sum = desired_sum - sum;

    // calculate n_sum (1,2,3,4,5,6)
    vector<int> ans = solve(required_sum, n);
    return ans;
}

int main(int argc, char const *argv[]) {
	vector<int> arr = {1,5,6};
	int n = 4;
	vector<int> ans = missingRolls(arr, 3, n);
	for (int i : ans) {
		cout << i << " ";
	}
	return 0;
}

//https://razorpay.com/blog/how-online-card-payments-work/