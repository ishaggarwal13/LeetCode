class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        res = 0
        seen = set()

        def dfs(startIndex):
            nonlocal res
            if startIndex == len(s):
                res = max(res, len(seen))
                return res

            for i in range(startIndex, len(s)):
                subString = s[startIndex:i+1]
                if subString not in seen:
                    seen.add(subString)
                    dfs(i+1)
                    seen.remove(subString)
        
        dfs(0)
        return res