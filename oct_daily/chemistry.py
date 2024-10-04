from typing import List

class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        sum = 0
        ans = 0
        n = len(skill)
        map = {}
        for i in skill:
            sum += i
            map[i] = 1 if i not in map else map[i] + 1
        k = sum / n
        k *= 2
        for i in range(n):
            curr = skill[i]
            if (map[curr] == 0): continue
            req = k - curr
            if (req not in map or map[req] == 0): return -1
            ans += (curr * req)
            map[curr] -= 1
            map[req] -= 1
        return int(ans)

solution = Solution()
print(f"{solution.dividePlayers([1,3,3,5,2,4])}")

