class Solution {
public:
    int sumCounts(vector<int>& nums) {
        // TC O(n^2) SC O(n)
        //loops for subarrays 
        int n = nums.size();
        int res = 0;
        for(int i=0; i<n; i++){
            unordered_set<int> set;
            for(int j=i; j<n; j++){
                set.insert(nums[j]);
                int distinct = set.size();
                res += distinct * distinct;
            }
        }
        return res;
    }
};