class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        bool elementInSubarray[10001] = {false};
        int left = 0, right = 0, maxSum = 0, currSum = 0;
        while (right < nums.size()) {
            if (!elementInSubarray[nums[right]]) {
                elementInSubarray[nums[right]] = true;
                currSum += nums[right];
                maxSum = max(maxSum, currSum);
                ++right;
            }
            else {
                elementInSubarray[nums[left]] = false;
                currSum -= nums[left];
                ++left;
            }
        }
        return maxSum;
    }
};