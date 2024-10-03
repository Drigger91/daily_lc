#include<bits/stdc++.h>
using namespace std;

int handle(vector<int>& nums) {
	int ans = 0;
	vector<int> groups(5, 0);
	for (int i : nums) groups[i]++;
	for (int i = 3; i < 5; i++) {
		int curr = groups[i];
		int req = groups[4 - i];
		if (curr == 0) continue;

		int canRideTogether = req == 0 ? curr : min(curr, req);

		ans += canRideTogether;

		groups[4 - i] -= canRideTogether;
		groups[i] -= canRideTogether;
		ans += max(groups[i], 0);
	}
	//cout<<"Ans "<<ans<<endl;
	int carry = 0;
	for (int i = 1; i <= 2; i++) {
		if (groups[i] <= 0) continue;
		int total = (groups[i] * i) + carry;
		ans += (total) / 4;
		carry = (total % 4);
		//cout<<ans<<" "<<carry<<" "<<total<<endl;
	}
	carry = (carry / 4) + (carry % 4 != 0);
	//cout<<"Carry : "<<carry<<endl;
	return ans + carry;
}
int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> nums;
	while (n--) {
		int k;
		cin >> k;
		nums.push_back(k);
	}
	cout << handle(nums)<<endl;
	return 0;
}