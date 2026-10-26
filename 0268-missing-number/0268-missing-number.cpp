class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //using XOR to cancel out same element with its index to find the missing number
        //xor - a^a=0, a^0=a if two same bits 1 1 or 0 0 return 0 two diff bits 1 0 or 0 1 return 1
        int ans = nums.size();
        for(int i=0; i<nums.size(); i++){
            ans ^= i;
            ans ^= nums[i];
        }

        return ans;
    }
};