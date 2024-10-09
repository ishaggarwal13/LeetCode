class Solution(object):
    def minSwaps(self, s):
        """
        :type s: str
        :rtype: int
        """
        count=0
        for i  in s:
          if i == '[':
            count+=1
          else:
            if count > 0:
              count-=1
        return (count+1)//2
        """ // to get interger value without fraction part"""
        