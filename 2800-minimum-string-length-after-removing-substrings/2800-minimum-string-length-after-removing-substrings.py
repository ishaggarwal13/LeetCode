class Solution(object):
    def minLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        index = 0
        for ch in s :
            if index > 0 and ((s[index - 1] == 'A' and ch == 'B') or (s[index - 1] == 'C' and ch == 'D')):
                index -= 1
            else:
                s = s[:index] + ch
                index += 1
        return index
        