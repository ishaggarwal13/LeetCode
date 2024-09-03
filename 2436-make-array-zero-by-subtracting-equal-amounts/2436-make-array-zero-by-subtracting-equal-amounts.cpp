class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //return the total of unique number exsist in array rather than 0
        unordered_set<int> mp;
        for(auto i: nums){
            if(i != 0){
                mp.insert(i);
            }
        }
        return mp.size();
    }
};