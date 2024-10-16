class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        res = "" 
        pq = []

        if a>0: heappush(pq, (-a, 'a')) #storing neg value to make max-heap
        if b>0: heappush(pq, (-b, 'b'))
        if c>0: heappush(pq, (-c, 'c'))

        while pq:
            count1, char1 = heapq.heappop(pq)
            count1 *= -1

            if len(res) >= 2 and res[-1] == res[-2] == char1:
                if not pq: return res

                count2, char2 = heapq.heappop(pq)
                count2 *= -1
                res += char2
                count2 -= 1 

                if count2: heapq.heappush(pq, (-1*count2, char2))

                heapq.heappush(pq, (-1*count1, char1))
                continue
            
            res += char1
            count1 -= 1

            if count1: heapq.heappush(pq, (-1*count1, char1))
        
        return res

        