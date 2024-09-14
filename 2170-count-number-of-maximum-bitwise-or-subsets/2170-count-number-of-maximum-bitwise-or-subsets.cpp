class Solution {
public:
    int cnt = 0;
    void count(int index, int curr, int target, vector<int>& nums){
        if(index == nums.size()){
            if(target == curr){
                cnt++;
            }
            return;
        }
        //include exclude
        count(index+1, (curr | nums[index]), target, nums);
        count(index+1 , curr, target, nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        //find maximum or
        for(auto num : nums){
            target |= num;
        }
        count(0, 0, target, nums);
        return cnt;
    }
};