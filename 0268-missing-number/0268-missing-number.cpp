class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();
        int mid = left + (right-left)/2;
       
        while(left < right){
            mid = left + (right-left)/2;
            if(nums[mid] > mid) right=mid;
            else left=mid+1;
        }
        return left;
    }
};