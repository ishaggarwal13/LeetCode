class Solution(object):
    def minLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        for ch in s:
            if stack and stack[-1] + ch in ('AB', 'CD'):
                stack.pop()
            else:
                stack.append(ch)
        return len(stack)
        