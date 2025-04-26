class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int badidx = -1, leftidx = -1, rightidx = -1;
        for(int i=0; i<nums.size(); i++){
            if(!(minK <= nums[i] && nums[i] <= maxK)){
                badidx = i;
            }

            if(nums[i] == minK) leftidx = i;
            if(nums[i] == maxK) rightidx = i;

            res += max(0, min(leftidx, rightidx) - badidx);
        }
        return res;
    }
};