class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        // making an array of maximum elements from right
        vector<int> maxright(n);
        // setting the last element same as nums array
        maxright[n-1] = nums[n-1];

        // traverse from end of nums and fill maxright from right to left
        for(int i=n-2; i>=0; i--){
            maxright[i] = max(maxright[i+1] , nums[i]);
        }

        // left pointer, right pointer, and final output
        int l=0, r=0, ans=0;
        // right pointer should ot exceeds size of array
        while(r < n) {
            // checks condition from nums array from left with maxright array with right pointer
            if(maxright[r] >= nums[l]){
                ans = max(ans, r-l);
                r++;
            } else {
                // if condition false will increase left pointer of nums
                l++;
            }
        }
        return ans;
    }
};