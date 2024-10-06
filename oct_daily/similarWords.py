class Solution:
    def handle(self, words1, words2):
        st = 0
        e1 = len(words1) - 1
        e2 = len(words2) - 1
        
        while st < len(words1) and words1[st] == words2[st]:
            st += 1
        
        while e1 >= 0 and words1[e1] == words2[e2]:
            e1 -= 1
            e2 -= 1
        
        return e1 < st

    def areSentencesSimilar(self, s1, s2):
        words1 = s1.split()
        words2 = s2.split()
        
        if len(words1) >= len(words2):
            return self.handle(words2, words1)
        return self.handle(words1, words2)
    
s1 = "My name is piyush"
s2 = "name is"

sol = Solution()
print("true" if sol.areSentencesSimilar(s1, s2) else "false")

print("true" if sol.areSentencesSimilar("name is this", "name") else "false")
