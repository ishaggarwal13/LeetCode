class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size(), n = queries.size();

        vector<int> prefixSum(m, 0); // while parity change, set 1, then prefixsum
        for (int i = 1; i < m; i++) {
            prefixSum[i] = prefixSum[i - 1] + ((nums[i - 1] & 1) ^ (nums[i] & 1));
        }

        vector<bool> res(n, false);
        for (int i = 0; i < n; i++) {
            int from = queries[i][0];
            int to = queries[i][1];
            res[i] = (prefixSum[to] - prefixSum[from] == to - from);
        }
        return res;
    }
};