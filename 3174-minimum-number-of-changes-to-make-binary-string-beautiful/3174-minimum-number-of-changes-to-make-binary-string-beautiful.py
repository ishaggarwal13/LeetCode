class Solution(object):
    def minChanges(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        count = 0
        i = 0
        while i < n - 1:
            if s[i] != s[i+1]:
                count += 1
            i+=2
        return count
        