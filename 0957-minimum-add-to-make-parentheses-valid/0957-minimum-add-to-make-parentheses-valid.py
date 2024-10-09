class Solution(object):
    def minAddToMakeValid(self, s):
        """
        :type s: str
        :rtype: int
        """
        open_brackets = 0
        close = 0
        for char in s:
            if char == '(':
                open_brackets += 1
            else :
                if open_brackets > 0:
                    open_brackets -= 1
                else:
                    close += 1
        return open_brackets + close

        