class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        //O(n) - without sorting 
        int less = 0;
        int greator = 0;
        for(auto num : nums){
            if(num < target) less++;
            if(num > target) greator++;
        }
        int n = nums.size() - less - greator;
        vector<int> res;
        for(int i=0; i<n; i++){
            res.push_back(i + less);
        }
        return res;
    }
};