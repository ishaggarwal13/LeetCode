class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //sort and then find 
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i+=2){ //jumps two times as elemets present twice and 1 unique
            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
        }
        return nums[nums.size()-1]; //return last element as we are not checking till last
    }
};