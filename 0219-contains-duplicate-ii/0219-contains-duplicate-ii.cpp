class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //o(n) & o(n)
        unordered_map<int, int> mp; //to store the index of the element
        
        for(int i=0; i<nums.size(); i++){
            int curr = nums[i];
            if(mp.find(curr) != mp.end()){ //find num in the mp
                if(abs(i - mp[curr]) <= k) return true;
            }
            mp[curr] = i; //storing the index of element
        }
        return false;
    }
};