class Solution(object):
    def minimumSteps(self, s):
        """
        :type s: str
        :rtype: int
        """
        black = 0
        swap = 0
        for i in s:
            if i == '1':
                black += 1
            else:
                swap += black
        return swap
        