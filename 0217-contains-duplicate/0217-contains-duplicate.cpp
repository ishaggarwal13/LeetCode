class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //tc:O(n) sc:O(n) for unordered_map or set
        unordered_map<int,int> mp;
        for(auto num : nums) mp[num]++;
        for(auto i : mp) {
            if(i.second >= 2) 
                return true;
        }
        return false;
    }
};