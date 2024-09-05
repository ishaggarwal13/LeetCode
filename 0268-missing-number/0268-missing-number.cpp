class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        //using XOR to cancel out same element with its index to find the missing number
        //xor - a^a=0, a^0=a if two same bits 1 1 or 0 0 return 0 two diff bits 1 0 or 0 1 return 1
        for(int i=0; i<nums.size(); i++){
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};