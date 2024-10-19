class Solution(object):
    def shortestPalindrome(self, s):
        i = 0
        n = len(s)

        for c in s[::-1]:
            if c == s[i]:
                i += 1

        if i == n:
            return s
        sub = s[i:]
        return sub[::-1] + self.shortestPalindrome(s[0:i]) + sub
        