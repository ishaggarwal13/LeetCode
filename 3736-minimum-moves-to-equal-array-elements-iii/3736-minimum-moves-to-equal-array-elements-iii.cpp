class Solution {
public:
    int minMoves(vector<int>& nums) {
        int high = *max_element(nums.begin(), nums.end());
        int moves = 0;
        for(int num : nums) moves += high - num;

        return moves;
    }
};