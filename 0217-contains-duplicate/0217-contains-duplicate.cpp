class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mp;
        for(auto num : nums){
            mp.insert(num);
        }
        return nums.size() != mp.size();
    }
};