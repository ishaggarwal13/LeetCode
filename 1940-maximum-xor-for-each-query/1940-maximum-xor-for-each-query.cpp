class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int kMask = (1 << maximumBit) - 1;
        const int n = nums.size();
        int accu = 0;
        for (int i : nums)
            accu ^= i;
        vector<int> res;
        res.reserve(n);
        for (int i = n - 1; i >= 0; i--) {
            res.push_back((~accu) & kMask);
            accu ^= nums[i];
        }
        return res;
    }
};