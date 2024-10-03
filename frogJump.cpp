#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int recursion(int pos, int k) {
	if (pos == 0) {
		return 0;
	}
	if (pos < 0) {
		return INT_MAX;
	}
	if (dp[pos] != -1) return dp[pos];
	int ans = INT_MAX;
	for (int i = 1; i <= k; i++) {
		int check = recursion(pos - i, k);
		if (check != INT_MAX) ans = min(check + 1, ans);
	}
	return dp[pos] = ans;

}
int handle(int x, int y, int k) {
	int min_x = x / k + (x % k > 0);
	int min_y  = y / k + (y % k > 0);
	//cout << min_x << " "<< min_y<<endl;
	int req = max(min_x, min_y);
	return req == min_y ? min_y + min_x + (min_y - min_x): min_x + min_y + (min_x - min_y - 1);
}
int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	while (n--) {
		int x, y, k;
		cin >> x >> y >> k;
		cout << handle(x, y, k)<< "\n";
	}
	return 0;
}