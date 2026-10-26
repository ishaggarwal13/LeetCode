class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> res;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                res.push_back(nums[i]);
            } else {
                count++;
            }
        }

        while(count > 0){
            res.push_back(0);
            count--;
        }

        nums = res;
    }
};