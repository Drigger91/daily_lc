#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>& nums) {
        int windowSize = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
        	nums.push_back(nums[i]);
        	windowSize += nums[i];
        }

        if (windowSize == 0) return 0;

        //denotes number of zeros
        int ans = INT_MAX;
        int curr = 0;

        //calculate for the first window
        for (int i = 0; i < windowSize; i++) {
        	curr += (nums[i] == 0);
        }

        ans = min(ans, curr);

        if (ans == 0) return 0;

        for (int i = 1; i <= (nums.size() - windowSize); i++) {
        	curr -= (nums[i - 1] == 0);
        	curr += (nums[windowSize + i - 1] == 0);
        	ans = min(ans, curr);
        }
        return ans;

}
int main() {
	vector<int> nums = {1,1,0,0,1};
	int ans = minSwaps(nums);
	cout << "Ans is : "<< ans<<endl;
	return 11; 
}

int main(int argc, char const *argv[]) {
        /* code */
        return 0;
}