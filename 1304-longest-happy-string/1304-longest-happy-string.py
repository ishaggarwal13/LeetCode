class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        res = "" 
        pq = []

        if a>0: heapq.heappush(pq, (-a, 'a')) #storing neg value to make max-heap
        if b>0: heapq.heappush(pq, (-b, 'b'))
        if c>0: heapq.heappush(pq, (-c, 'c'))

        while pq:
            count1, char1 = heapq.heappop(pq)

            if len(res) >= 2 and res[-1] == char1 and res[-2] == char1:
                if not pq: break

                count2, char2 = heapq.heappop(pq)
                res += char2
                count2 += 1 #as we had stroed neg values

                if count2 < 0: heapq.heappush(pq, (count2, char2))

                heapq.heappush(pq, (count1, char1))
            else: 
                res += char1
                count1 += 1

                if count1 < 0: heapq.heappush(pq, (count1, char1))
        
        return res

        