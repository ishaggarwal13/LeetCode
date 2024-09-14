class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //find maximum element
        int maxval = *max_element(nums.begin(), nums.end());
        //length of longest continous subrray with maxi ele
        int ans=0;
        int j=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != maxval){
                j = i; //inc j value till we find the same maxval
            }
            ans = max(ans, i - j);
        }
        return ans;
    }
};