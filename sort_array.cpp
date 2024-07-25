#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>& left, vector<int>& right, int s, int e) {
	int i = 0, j = 0;
	vector<int> ans;
	while (i < left.size() && j < right.size()) {
		if (left[i] > right[j]) {
			ans.push_back(right[j++]);
		} else {
			ans.push_back(left[i++]);
		}
	}
	while (i < left.size()) ans.push_back(left[i++]);
	while (j < right.size()) ans.push_back(right[j++]);
	return ans;
}
vector<int> mergeSort(int s, int e, vector<int>& nums) {
	if (s >= nums.size()) return {};
	if (s >= e) return {nums[e]};
	int mid = s + (e - s)/2;
	vector<int> left = mergeSort(s, mid, nums);
	vector<int> right = mergeSort(mid + 1, e, nums);
	vector<int> merged = merge(left, right, s, e);
	return merged;
}
vector<int> sortArray(vector<int>& nums) {
    return mergeSort(0, nums.size(), nums);
}

int main() {
	vector<int> test = {0,9,79,7,79,9,7,97};
	vector<int> check = sortArray(test);
	for (int i: check) cout<<i<<endl;
	return 0;
}