class Solution(object):
    def dividePlayers(self, skill):
        """
        :type skill: List[int]
        :rtype: int
        """
        n = len(skill)
        skill.sort()

        if(n==2): return skill[0] * skill[1]

        val = skill[0] + skill[n-1]
        ans = 0

        for i in range(n//2):
            if val != (skill[i] + skill[-i-1]):
                return -1
            ans += (skill[i] * skill[-i-1])
        
        return ans


        