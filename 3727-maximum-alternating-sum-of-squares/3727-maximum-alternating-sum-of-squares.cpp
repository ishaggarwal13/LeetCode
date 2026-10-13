class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        //O(n logn) sorted one
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });

        int n = nums.size();
        int pos = (n + 1) / 2;

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            long long sq = 1LL * nums[i] * nums[i];

            if(i < pos)
                ans += sq;
            else
                ans -= sq;
        }

        return ans;
    }
};