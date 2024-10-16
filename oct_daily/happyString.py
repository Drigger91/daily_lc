import heapq


class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        pq = [];
        heapq.heappush(pq, (-a, 'a'))
        heapq.heappush(pq, (-b, 'b'))
        heapq.heappush(pq, (-c, 'c'))


        # using array instead of string as in python str += some_string takes O(n)
        ans = []

        while pq:
            cnt, ch = heapq.heappop(pq)
            if (cnt == 0): continue

            if len(ans) >= 2 and ans[-1] == ch and ans[-2] == ch:
                if not pq: break
                cnt2, ch2 = heapq.heappop(pq)
                print(cnt2, ch2)
                if cnt2 == 0: break

                ans.append(ch2)

                if (cnt2 + 1 < 0): heapq.heappush(pq, (cnt2 + 1, ch2))
                heapq.heappush(pq, (cnt, ch))

            else:
                ans.append(ch)
                if (cnt + 1 < 0): heapq.heappush(pq, (cnt + 1, ch))
        return "".join(ans)

sol = Solution()

print(f"happy string for a = 1, b = 1, c = 7 {sol.longestDiverseString(1,1,7)}")