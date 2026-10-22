class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        // Find index of 0
        int start = find(nums.begin(), nums.end(), 0)
                    - nums.begin();

        bool asc = true, desc = true;

        // Check cyclic order starting from 0
        for (int i = 1; i < n; i++) {
            int value = nums[(start + i) % n];

            // Expected: 0, 1, 2, ..., n-1
            if (value != i)
                asc = false;

            // Expected: 0, n-1, n-2, ..., 1
            if (value != n - i)
                desc = false;

            // Neither pattern is possible
            if (!asc && !desc)
                return -1;
        }

        // Cyclically increasing
        if (asc)
            return min(start, n - start + 2);

        // Cyclically decreasing
        return min(n - start, start + 2);
    }
};