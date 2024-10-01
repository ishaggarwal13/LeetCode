class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // try the largest one
        for (int i = nums.size() - 1; i >= 2; i--) {
            // check if a + b > c is satisfied
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                // valid! non-zero area
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return 0;
    }
};