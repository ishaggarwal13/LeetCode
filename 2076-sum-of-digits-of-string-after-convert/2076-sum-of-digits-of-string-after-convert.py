class Solution(object):
    def getLucky(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        num = 0
        total = 0
        for c in s:
            num = ord(c) - 96
            while num > 0:
                total += num % 10
                num = num // 10
        num = total
        total = 0

        for _ in range(k-1):
            while num > 0:
                total += num % 10
                num = num // 10
            num = total
            total = 0
        return num