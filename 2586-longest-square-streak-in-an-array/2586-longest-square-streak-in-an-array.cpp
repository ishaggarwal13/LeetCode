class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> seen(nums.begin(), nums.end());

        int maxStreak = 0;

        for(auto num : nums){
            int currNum = num;
            int streak = 0;

            while(seen.find(currNum) != seen.end()){
                streak++;
                seen.erase(currNum);
                if (currNum > 100000 || currNum > sqrt(100000)) break;
                
                currNum *= currNum;
            }

            if(streak >= 2){
                maxStreak = max(maxStreak, streak);
            }
        }

        return (maxStreak > 1) ? maxStreak : -1;
    }
};