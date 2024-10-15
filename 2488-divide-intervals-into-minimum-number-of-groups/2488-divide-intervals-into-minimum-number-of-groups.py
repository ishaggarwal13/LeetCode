class Solution(object):
    def minGroups(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        start = []
        end = []

        for interval in intervals:
            start.append(interval[0])
            end.append(interval[1])
        
        start.sort()
        end.sort()

        group_count = 0
        end_ptr = 0

        for s in start:
            if s > end[end_ptr]:
                end_ptr += 1
            else:
                group_count += 1
        
        return group_count
        