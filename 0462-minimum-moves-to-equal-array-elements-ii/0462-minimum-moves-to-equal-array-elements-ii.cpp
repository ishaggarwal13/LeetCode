class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //without sorting in O(n) using Nth elemnent to place median in its correct position
        // nth element - finds the element that would be at a particular index if the array were sorted, without sorting the entire array
        int n = nums.size();
        nth_element(nums.begin(),
                    nums.begin() + n/2,
                    nums.end());
        
        int median = nums[n/2];

        long long moves = 0;

        for(int num : nums) moves += abs((long long)num - median);

        return (int)moves;
    }
};