class Solution(object):
    def getLucky(self, s, k):

        res = 0

        C = Counter(s)

        del(s)

        for c in C:

            a = ord(c) - 96
            res += (a%10 + a//10)*C[c]

        k -= 1

        while k != 0:

            if res >= 10:

                p, res = res, 0

                while p != 0:

                    res += p%10
                    p//=10

                k -= 1

                continue

            break
            
        return res