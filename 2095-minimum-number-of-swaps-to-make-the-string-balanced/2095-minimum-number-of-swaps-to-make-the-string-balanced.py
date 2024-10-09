class Solution(object):
    def minSwaps(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        for i in s :
            if i == '[':
                stack.append(i) 
            elif stack:
                stack.pop()

        return (len(stack) + 1) // 2 
        """to get interger value without fraction part"""
        