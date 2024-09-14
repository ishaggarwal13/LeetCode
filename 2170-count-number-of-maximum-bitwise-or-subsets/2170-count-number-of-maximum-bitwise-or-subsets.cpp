class Solution {
public:
    int count(int index, int curr, int target, vector<int>& nums){
        if(index == nums.size()){
            if(target == curr){
                return 1;
            }
            return 0;
        }
        //include exclude
         return count(index+1, (curr | nums[index]), target, nums) + 
                count(index+1 , curr, target, nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        //find maximum or
        for(auto num : nums){
            target |= num;
        }
        return count(0, 0, target, nums);
    }
};