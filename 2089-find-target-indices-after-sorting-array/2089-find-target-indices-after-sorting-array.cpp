class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        //O(n) - without sorting - can use iota filling a range of values sequentially
        int less = 0;
        int same = 0;
        for(int num : nums){
            if(num < target) less++;
            if(num == target) same++;
        }
        // creating same number of target res vector
        vector<int> res(same);
        iota(res.begin(), res.end(), less);
        return res;
    }
};