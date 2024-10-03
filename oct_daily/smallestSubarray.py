from typing import List

class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total = 0
        for i in nums:
            total += i
            total = total % p
        if (total == 0):
            return 0
        sum = 0
        n = len(nums)
        ans = n + 2
        map = {0 : -1}
        for i in range(n):
            sum += nums[i]
            sum = sum % p
            req = (sum - total + p) % p
            if req in map:
                ans = min(ans, i - map[req])
            map[sum] = i
        return -1 if ans >= n else ans

    # int minSubarray(vector<int>& nums, int p) {
    #     unordered_map<int,int> map;
    #     map[0] = -1;
    #     int total = 0;
    #     for(int i : nums){
    #         total += i;
    #         total = total % p;
    #     }
    #     int sum = 0;
    #     int ans = INT_MAX;
    #     if(total == 0) return 0;
    #     for(int i = 0;i<nums.size();i++){
    #         sum += nums[i];
    #         sum = sum % p;
    #         int search = (sum - total + p) % p; //since sum - total will be <= 0
    #         if(map.find(search) != map.end()){
    #             ans = min(ans,i - map[search]);
    #         }
    #         map[sum] = i;
    #     }
    #     return ans >= nums.size() ? -1 : ans;

solution = Solution()
print(solution.minSubarray([1,2,3,4], 6))
print(solution.minSubarray([1,2,3], 6))
print(solution.minSubarray([6,3,5,1], 9))
print(solution.minSubarray([3,1,4,2], 6))