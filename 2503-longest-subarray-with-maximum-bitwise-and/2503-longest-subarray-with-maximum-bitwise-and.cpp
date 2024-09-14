class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //find maximum element
        int maxi = 0;
        for(auto num : nums){
            maxi = max(maxi, num);
        }
        //length of longest continous subrray with maxi ele
        int ans=0, sublen=0;
        for(auto num : nums){
            if(num == maxi){
                sublen++;
                ans = max(ans, sublen);
            } else {
                sublen=0;
            }
        }
        return ans;
    }
};