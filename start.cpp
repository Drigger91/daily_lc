#include<bits/stdc++.h>
using namespace std;
void mergeSortedArrays(vector<int>& arr1, vector<int>& arr2, int m) {
	int n = arr2.size();
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;
	while (i >= 0 && j >= 0) {
		if (arr1[i] > arr2[j]) {
			arr1[k--] = arr1[i--];
		} else {
			arr1[k--] = arr2[j--];
		}
	}
	while (j >= 0) {
		arr1[k--] = arr2[j--];
	}
}
int kadane(vector<int>& nums) {
	int currentSum = nums[0], maxSum = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		currentSum = max(currentSum + nums[i], nums[i]);
		maxSum = max(currentSum, maxSum);
	}
	return maxSum;
}
int main() {
	vector<int> nums = {-1,-2,-300,-100,-5};
	cout<<" Ans is : " << kadane(nums)<<endl;
	return 0;
}