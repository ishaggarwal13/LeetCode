class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0LL);
        return n * mx - sum;
    }
};