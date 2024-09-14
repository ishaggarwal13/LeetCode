class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //find maximum element
        int maxval = *max_element(nums.begin(), nums.end());
        //length of longest continous subrray with maxi ele
        int ans=INT_MIN;
        int i=0, j=0; //two pointers to put i at start of window and j traverse till contigous eleemnt
        while(j<nums.size()){
            if(nums[j] == maxval){
                ans = max(ans, j-i+1); //end-start+1
                j++;
            } else {
                j++;
                i=j; //i will inc till element found
            }
        }
        return ans;
    }
};