class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //brute force - O(n^2)
        sort(nums.begin(), nums.end());
        int count=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                int x = nums[i];
                count++;
                for(int j=i; j<nums.size(); j++){
                    nums[j] = nums[j] - x;
                }
            }
        }
        return count;
    }
};