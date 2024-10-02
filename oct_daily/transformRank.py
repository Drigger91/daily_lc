from typing import List

class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rank = []
        _set = set()
        for i in arr:
            _set.add(i)
        sorted_unique = sorted(_set)
        # sorted_unique = reversed(sorted_unique)
        rank_map = {num: idx + 1 for idx, num in enumerate(sorted_unique)}
        return [rank_map[num] for num in arr]
        

# solution = Solution();
# arr = solution.arrayRankTransform([4,3,4,2])
# print(arr);