class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //tc:O(nlogn) sc:O(n)
        return nums.size() != set<int>(nums.begin(), nums.end()).size();
    }
};