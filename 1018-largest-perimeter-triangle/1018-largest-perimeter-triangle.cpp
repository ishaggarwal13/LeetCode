class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, k = 2, ans = 0;
        while(k < nums.size()){
            if(nums[i] + nums[j] > nums[k]){
                ans = max(ans, nums[i] + nums[j] + nums[k]);
            }
            i++;
            j++;
            k++;
        }
        return ans;
    }
};