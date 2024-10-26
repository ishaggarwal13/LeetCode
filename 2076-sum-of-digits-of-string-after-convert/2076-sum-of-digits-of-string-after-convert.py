class Solution:
    def getLucky(self, s: str, k: int) -> int:
        check="abcdefghijklmnopqrstuvwxyz"
        sm=""
        for i in s:
            sm+=str(check.index(i)+1)

        itr=0
        while k>0:
            for i in sm:
                itr+=int(i)
            k-=1
            ret=itr
            sm=str(itr)
            itr=0
        return ret    