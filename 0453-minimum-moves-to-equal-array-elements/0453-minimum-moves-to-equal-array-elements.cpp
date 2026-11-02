class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int mini = ranges::min(nums);
        int n = nums.size();
        return sum - (mini * n);
    }
};