class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //O(n) & O(1);
        int ones = 0, twos = 0;
        for(int i=0; i<nums.size(); i++){
            ones = (ones^nums[i]) & ~twos;
            twos = (twos^nums[i]) & ~ones;
        }
        return ones;
    }
};